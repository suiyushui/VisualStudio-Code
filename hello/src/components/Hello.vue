<template>
  <div>
    <h1>Hello页面</h1>
    <nav>
      <router-link to="/Hello/bullsAndCows" class="router-link">猜数字</router-link>
      <router-link to="/Hello/snake" class="router-link">贪吃蛇</router-link>
    </nav>
    <router-view></router-view>
  </div>
</template>

<style scoped>
/* 全局样式 */
.router-link {
  text-decoration: none;
}

.router-link:hover {
  text-decoration: underline;
}
</style>