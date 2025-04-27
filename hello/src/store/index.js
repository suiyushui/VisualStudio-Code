import { createStore } from 'vuex'  // Vuex 4 的写法

export default createStore({
  state: { 
    count: 0,
    name: 'Vuex',
    todos:[
        {id:1, text:'Learn Vuex', done:false},
        {id:2, text:'Learn Vue', done:true},
        {id:3, text:'Build something awesome', done:false}
    ],
  },
  mutations: {
    increment (state,n) {
      state.count+=n,
      console.log('count is incremented')
    },
  },
  getters:{
    doneTodos: state => state.todos.filter(todo => todo.done),
    remainingTodos: state => state.todos.filter(todo =>!todo.done)
  }
})