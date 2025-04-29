<template>
  <div id="app">
    <img src="./assets/logo.png" alt="Vue.png">
    <h1>Vue.js App</h1>
    <div>
      <p>这是一个简单的Vue.js应用程序。</p>
      <p>你可以在这里添加更多的内容。</p>
    </div> 
    <nav>
      <router-link to="/New_Project" class="router-link">项目</router-link>
      <router-link to="/Hello" class="router-link">开始</router-link>
      <router-link to="/Email" class="router-link">邮箱</router-link>
      <router-link to="/Movie" class="router-link">电影</router-link>
    </nav>
    <router-view></router-view>
  </div>
</template>

<script>
import Hello from './components/Hello.vue'
import Movie from './components/Movie.vue';
import Email from './components/Email.vue';
import New_Project from './components/new_project.vue';
import axios from 'axios';


export default {
  name: 'App',
  data() {
    return {
    }
  },
  created() {
    console.log("app组件被创建");
  },
  mounted() {
    axios.get("/product/search").then( ren=>{
      console.log(ren);
    });
    console.log("app组件被挂载");
  }
}
</script>

<style>
/* 全局变量定义 */
:root {
  --primary-color: #41eea0;
  --secondary-color: #35495e;
  --router-link-hover-color: #33a06f;
  --text-light: #ffffff;
  --transition-speed: 0.3s;
}

/* 主体容器样式 */
#app {
  font-family: 'Segoe UI', Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
  max-width: 1200px;
  margin: 0 auto;
  padding: 2rem;
  min-height: 100vh;
  display: flex;
  justify-content: center;
  flex-direction: column;
  align-items: center;
}

/* 导航样式 */
nav {
  margin: 2rem 0;
  display: flex;
  gap: 1.5rem;
  flex-wrap: wrap;
  justify-content: center;
}

/* 路由链接样式 */
.router-link {
  padding: 0.8rem 1.5rem;
  border-radius: 8px;
  text-decoration: none;
  color: var(--text-light);
  background: linear-gradient(135deg, var(--primary-color), var(--secondary-color));
  transition: transform var(--transition-speed) ease, box-shadow var(--transition-speed) ease;
  box-shadow: 0 2px 5px rgba(71, 64, 64, 0.1);
}

.router-link:hover {
  transform: translateY(-2px);
  box-shadow: 0 3px 6px rgba(0,0,0,0.1); /* 适当减小box-shadow变化幅度 */
  background: linear-gradient(135deg, var(--router-link-hover-color), var(--secondary-color));
}

/* 激活的路由链接样式 */
.router-link-active {
  position: relative;
  font-weight: 600;
}

.router-link-active::after {
  content: '';
  position: absolute;
  bottom: -5px;
  left: 50%;
  transform: translateX(-50%);
  width: 60%;
  height: 2px;
  background: var(--text-light);
}

/* 小屏幕适配 */
@media (max-width: 768px) {
  #app {
    padding: 1rem;
  }
  
  nav {
    gap: 1rem;
    margin: 1rem 0;
  }
  
  .router-link {
    padding: 0.6rem 1rem;
    font-size: 0.9rem;
  }
}

/* 减少动画适配 */
@media (prefers-reduced-motion: reduce) {
  .router-link {
    transition: none;
  }
}

/* 标题样式 */
h1 {
  font-size: 2.5rem;
  margin-bottom: 1.5rem;
  background: linear-gradient(45deg, var(--secondary-color), var(--primary-color));
  -webkit-background-clip: text;
  -moz-background-clip: text;
  -o-background-clip: text;
  background-clip: text;
  color: transparent;
}

/* 段落样式 */
p {
  line-height: 1.6;
  max-width: 65ch;
  margin: 1rem auto;
  color: var(--secondary-color);
}
</style>
