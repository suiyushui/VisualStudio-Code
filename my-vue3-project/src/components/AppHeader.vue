<template>
    <header class="myheader">
      <div></div>
      <h4>图片</h4>
      <div class="search-icon">
        <i class="fas fa-search"></i>
      </div>
    </header>
  </template>
  
  <script>
  export default {
    name: 'AppHeader' 
  }
  </script>
  
  <style scoped>
  .myheader {
    margin-top: 0;
    background-color: rgba(250, 235, 215, 0.7);
    width: 100%;
    height: 2.3333rem;
    position: fixed;
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 0 .4rem;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    z-index: 1000;
    backdrop-filter: blur(5px);
  }
  
  .search-icon {
    width: 1.5rem;
    height: 1.5rem;
    color: #333;
  }
  
  .search-icon i {
    font-size: 1rem;
    vertical-align: middle;
  }
  </style>