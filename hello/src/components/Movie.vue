<template>
    <div id="">
      <h1>{{ year }}年电影列表</h1>
      <div v-if="isLoading">加载中...</div>
      <div v-else>
        <table>
          <thead>
            <tr>
              <th>电影名称</th>
              <th>导演</th>
              <th>主演</th>
              <th>上映年份</th>
            </tr>
          </thead>
          <tbody>
            <tr v-for="movie in movies" :key="movie.id" :class="{ 'bg-white': movie.id % 2 === 0, 'bg-light-green': movie.id % 2 !== 0 }">
              <td>{{ movie.title }}</td>
              <td>{{ movie.director }}</td>
              <td>{{ movie.actors.join(', ') }}</td>
              <td>{{ movie.year }}</td>
            </tr>
          </tbody>
        </table>
      </div>
    </div>
  </template>
  
  <script>
  import axios from 'axios';
  
  export default {
    name: "Movie",
    props: ["year"],
    data() {
      return {
        movies: [],
        isLoading: true
      };
    },
    async created() {
      try {
        const response = await axios.get(`/api/movies?year=${this.year}`);
        this.movies = response.data;
      } catch (error) {
        console.error('获取电影数据失败:', error);
      } finally {
        this.isLoading = false;
      }
    }
  };
  </script>
  
  <style scoped>
  h1 {
    text-align: left;
  }
  .bg-white {
    background-color: white;
  }
  
  .bg-light-green {
    background-color: rgba(144, 238, 144, 0.5);
  }
  </style>