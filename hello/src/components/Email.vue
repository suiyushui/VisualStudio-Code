<template>
  <div id="email_component">
    <h1>用户邮件列表</h1>

    <!-- 搜索和过滤区域 -->
    <div class="toolbar">
      <input
        v-model="searchQuery"
        placeholder="搜索邮箱..."
        @input="handleSearch"
        class="search-input"
      />
      <select v-model="pageSize" @change="fetchUsers" class="page-size-select">
        <option value="5">每页5条</option>
        <option value="10">每页10条</option>
        <option value="20">每页20条</option>
      </select>
    </div>

    <!-- 状态显示 -->
    <div v-if="isLoading" class="status-message loading">
      <i class="fas fa-spinner fa-spin"></i> 数据加载中...
    </div>
    <div v-else-if="error" class="status-message error">
      <i class="fas fa-exclamation-circle"></i> {{ error }}
    </div>
    <div v-else-if="dataEmpty" class="status-message info">
      <i class="fas fa-info-circle"></i> 没有找到用户数据
    </div>

    <!-- 数据表格 -->
    <table v-if="!isLoading && !error && !dataEmpty" class="user-table">
      <thead>
        <tr>
          <th @click="sortBy('id')" class="sortable">
            ID <i :class="sortIcon('id')"></i>
          </th>
          <th @click="sortBy('name')" class="sortable">
            姓名 <i :class="sortIcon('name')"></i>
          </th>
          <th @click="sortBy('email')" class="sortable">
            邮箱 <i :class="sortIcon('email')"></i>
          </th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="user in users" :key="user.id">
          <td>{{ user.id }}</td>
          <td>{{ user.name }}</td>
          <td>{{ user.email }}</td>
        </tr>
      </tbody>
    </table>

    <!-- 分页控制 -->
    <div v-if="!isLoading && !error && !dataEmpty" class="pagination-controls">
      <div class="pagination-info">
        显示 {{ rangeStart }}-{{ rangeEnd }} 条，共 {{ totalElements }} 条记录
      </div>
      <div class="pagination-buttons">
        <button
          @click="goToFirstPage"
          :disabled="currentPage === 0"
          class="pagination-button"
        >
          <i class="fas fa-angle-double-left"></i>
        </button>
        <button
          @click="prevPage"
          :disabled="currentPage === 0"
          class="pagination-button"
        >
          <i class="fas fa-angle-left"></i>
        </button>

        <template v-for="page in displayedPages" :key="page">
          <button
            @click="goToPage(page)"
            :class="{ active: currentPage === page }"
            class="pagination-button"
          >
            {{ page + 1 }}
          </button>
        </template>

        <button
          @click="nextPage"
          :disabled="currentPage >= totalPages - 1"
          class="pagination-button"
        >
          <i class="fas fa-angle-right"></i>
        </button>
        <button
          @click="goToLastPage"
          :disabled="currentPage >= totalPages - 1"
          class="pagination-button"
        >
          <i class="fas fa-angle-double-right"></i>
        </button>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios';
import debounce from 'lodash.debounce';

export default {
  name: "EmailComponent",
  data() {
    return {
      users: [],
      isLoading: false,
      error: null,
      searchQuery: '',
      currentPage: 0,
      pageSize: 10,
      totalPages: 0,
      totalElements: 0,
      sortField: 'id',
      sortDirection: 'asc',
      debouncedSearch: null
    };
  },
  computed: {
    dataEmpty() {
      return this.users.length === 0 && !this.isLoading && !this.error;
    },
    rangeStart() {
      return this.currentPage * this.pageSize + 1;
    },
    rangeEnd() {
      const end = (this.currentPage + 1) * this.pageSize;
      return end > this.totalElements ? this.totalElements : end;
    },
    displayedPages() {
      const pages = [];
      const maxVisiblePages = 5;
      let startPage = Math.max(0, this.currentPage - Math.floor(maxVisiblePages / 2));
      let endPage = startPage + maxVisiblePages - 1;

      if (endPage >= this.totalPages) {
        endPage = this.totalPages - 1;
        startPage = Math.max(0, endPage - maxVisiblePages + 1);
      }

      for (let i = startPage; i <= endPage; i++) {
        pages.push(i);
      }

      return pages;
    }
  },
  created() {
    this.debouncedSearch = debounce(this.fetchUsers, 500);
    this.fetchUsers();
  },
  methods: {
    async fetchUsers() {
      this.isLoading = true;
      this.error = null;

      try {
        const response = await axios.get('/api/users', {
          params: {
            page: this.currentPage,
            size: this.pageSize,
            sort: `${this.sortField},${this.sortDirection}`,
            search: this.searchQuery || undefined
          }
        });

        const apiResponse = response.data;
        if (apiResponse && apiResponse.data) {
          this.users = apiResponse.data.content;
          this.totalPages = apiResponse.data.totalPages;
          this.totalElements = apiResponse.data.totalElements;
        }
      } catch (error) {
        console.error("获取用户数据失败:", error);
        this.error = `获取用户数据失败: ${error.response?.data?.message || error.message}`;
      } finally {
        this.isLoading = false;
      }
    },

    handleSearch() {
      this.currentPage = 0;
      this.debouncedSearch();
    },

    sortBy(field) {
      if (this.sortField === field) {
        this.sortDirection = this.sortDirection === 'asc' ? 'desc' : 'asc';
      } else {
        this.sortField = field;
        this.sortDirection = 'asc';
      }
      this.fetchUsers();
    },

    sortIcon(field) {
      if (this.sortField !== field) return 'fas fa-sort';
      return this.sortDirection === 'asc' ? 'fas fa-sort-up' : 'fas fa-sort-down';
    },

    goToPage(page) {
      if (page >= 0 && page < this.totalPages && page !== this.currentPage) {
        this.currentPage = page;
        this.fetchUsers();
      }
    },

    prevPage() {
      if (this.currentPage > 0) {
        this.currentPage--;
        this.fetchUsers();
      }
    },

    nextPage() {
      if (this.currentPage < this.totalPages - 1) {
        this.currentPage++;
        this.fetchUsers();
      }
    },

    goToFirstPage() {
      if (this.currentPage !== 0) {
        this.currentPage = 0;
        this.fetchUsers();
      }
    },

    goToLastPage() {
      if (this.currentPage !== this.totalPages - 1) {
        this.currentPage = this.totalPages - 1;
        this.fetchUsers();
      }
    }
  }
}
</script>

<style scoped>
#email_component {
  max-width: 1200px;
  margin: 0 auto;
  padding: 20px;
  font-family: 'Arial', sans-serif;
}

.toolbar {
  display: flex;
  justify-content: space-between;
  margin-bottom: 20px;
  gap: 15px;
}

.search-input {
  flex-grow: 1;
  padding: 8px 12px;
  border: 1px solid #ddd;
  border-radius: 4px;
  font-size: 14px;
}

.page-size-select {
  padding: 8px 12px;
  border: 1px solid #ddd;
  border-radius: 4px;
  background-color: white;
}

.status-message {
  padding: 15px;
  margin: 20px 0;
  border-radius: 4px;
  text-align: center;
  font-size: 16px;
}

.status-message i {
  margin-right: 8px;
}

.loading {
  background-color: #e6f7ff;
  color: #1890ff;
}

.error {
  background-color: #fff2f0;
  color: #ff4d4f;
}

.info {
  background-color: #f6ffed;
  color: #52c41a;
}

.user-table {
  width: 100%;
  border-collapse: collapse;
  margin: 20px 0;
  box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);
}

.user-table th,
.user-table td {
  padding: 12px 15px;
  border: 1px solid #e8e8e8;
  text-align: left;
}

.user-table th {
  background-color: #fafafa;
  font-weight: 500;
  position: relative;
}

.sortable {
  cursor: pointer;
  user-select: none;
}

.sortable:hover {
  background-color: #f0f0f0;
}

.user-table tr:nth-child(even) {
  background-color: #f9f9f9;
}

.user-table tr:hover {
  background-color: #f5f5f5;
}

.pagination-controls {
  display: flex;
  flex-direction: column;
  align-items: center;
  margin-top: 30px;
  gap: 15px;
}

.pagination-info {
  font-size: 14px;
  color: #666;
}

.pagination-buttons {
  display: flex;
  gap: 5px;
}

.pagination-button {
  min-width: 36px;
  height: 36px;
  padding: 0 8px;
  border: 1px solid #d9d9d9;
  background-color: white;
  color: rgba(0, 0, 0, 0.65);
  border-radius: 4px;
  cursor: pointer;
  display: flex;
  align-items: center;
  justify-content: center;
  transition: all 0.3s;
}

.pagination-button:hover:not(:disabled) {
  color: #1890ff;
  border-color: #1890ff;
}

.pagination-button:disabled {
  opacity: 0.5;
  cursor: not-allowed;
}

.pagination-button.active {
  background-color: #1890ff;
  color: white;
  border-color: #1890ff;
}

@media (max-width: 768px) {
  .toolbar {
    flex-direction: column;
  }

  .pagination-buttons {
    flex-wrap: wrap;
    justify-content: center;
  }
}
</style>