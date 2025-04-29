<template>
  <div id="app">
    <AppHeader />
    <MainContent />
    <AppFooter />
  </div>
</template>

<script>
import AppHeader from './components/AppHeader.vue'
import MainContent from './components/MainContent.vue'
import AppFooter from './components/AppFooter.vue'

export default {
  name: 'App',
  components: {
    AppHeader,
    MainContent,
    AppFooter
  }
}
</script>

<style>
body {
  font-family: Arial, sans-serif;
  background-color: #f4f4f4;
  color: #333;
  line-height: 1.6;
  display: flex;
  flex-direction: column;
  min-height: 100vh;
  margin: 0;
  padding: 0;
}

main {
  flex: 1;
  padding-top: 2.3333rem;
  padding-bottom: 60px;
  background-color: #ffffff;
}

footer {
  background-color: #f5f5f5;
  padding: 10px 0;
  border-top: 1px solid #ddd;
  width: 100%;
  position: fixed;
  bottom: 0;
  z-index: 1000;
}
</style>