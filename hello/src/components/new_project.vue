<template>
    <div>
      {{ count }} <!-- 直接使用计算属性 -->
      <button @click="increment(2)">+1</button>  <!-- 使用方法更清晰 -->
    </div>
    <div>
        <ul>
            <li v-for="todo in remainingTodos" :key="todo.id">{{ todo.text }}</li>
        </ul>
    </div>
  </template>
  
  <script>
  import { mapState, mapMutations, mapGetters,remainingTodos } from 'vuex';
  
  export default {
    name: 'NewProject',
    computed: {
        ...mapState(['count','name','todos']), // 映射 state
        ...mapGetters(['doneTodos','remainingTodos',]),  // 映射 getters
    },
    methods: {
      ...mapMutations(['increment'])  // 映射 mutations
    }
  }
  </script>