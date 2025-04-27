<template>
    <div class="game-container">
      <h1>猜数字小游戏</h1>
      <p>请输入一个1到100之间的数字：</p>
      <input type="number" v-model="guess" min="1" max="100" @keyup.enter="checkGuess" />
      <button @click="checkGuess">猜</button>
      <p>{{ message }}</p>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        secretNumber: Math.floor(Math.random() * 100) + 1,
        guess: null,
        message: ''
      };
    },
    methods: {
      checkGuess() {
        if (isNaN(this.guess) || this.guess < 1 || this.guess > 100) {
          this.message = '请输入1到100之间的有效数字！';
          return;
        }
        if (this.guess === this.secretNumber) {
          this.message = '恭喜你，猜对了！';
          this.secretNumber = Math.floor(Math.random() * 100) + 1; // 重新生成随机数
          this.guess = null;
        } else if (this.guess < this.secretNumber) {
          this.message = '太小了，再试一次！';
        } else if (this.guess > this.secretNumber) {
          this.message = '太大了，再试一次！';
        }
      }
    }
  };
  </script>
  
  <style scoped>
  .game-container {
    text-align: center;
    margin-top: 50px;
  }
  
  input[type="number"] {
    width: 50px;
    padding: 5px;
    margin-right: 10px;
  }
  
  button {
    padding: 5px 10px;
  }
  
  p {
    margin-top: 20px;
    font-size: 18px;
  }
  </style>