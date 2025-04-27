<template>
    <div id="snake">
        <h1>贪吃蛇小游戏</h1>
        <canvas id="game-canvas" width="400" height="400"></canvas>
        <div class="controls">
            <button id="start-btn" @click="startGame">开始游戏</button>
            <button id="pause-btn" @click="pauseGame">暂停游戏</button>
            <button id="resume-btn" @click="resumeGame">继续游戏</button>
            <button id="restart-btn" @click="restartGame">重新开始</button>
        </div>
        <div class="scores">
            <p id="score">得分: {{ score }}</p>
            <p id="high-score">最高分: {{ highScore }}</p>
        </div>
    </div>
</template>

<script>
export default {
    name: 'SnakeGame',
    data() {
        return {
            canvas: null,
            ctx: null,
            snake: [],
            food: {},
            direction: 'right',
            nextDirection: 'right',
            gameInterval: null,
            score: 0,
            highScore: 0,
            isPaused: false,
            gridSize: 20,
            canvasSize: 400
        }
    },
    mounted() {
        this.canvas = document.getElementById('game-canvas');
        this.ctx = this.canvas.getContext('2d');
        this.initGame();
        window.addEventListener('keydown', this.handleKeyPress);
    },
    beforeDestroy() {
        window.removeEventListener('keydown', this.handleKeyPress);
        clearInterval(this.gameInterval);
    },
    methods: {
        initGame() {
            // 初始化蛇身
            this.snake = [
                {x: 5 * this.gridSize, y: 10 * this.gridSize},
                {x: 4 * this.gridSize, y: 10 * this.gridSize},
                {x: 3 * this.gridSize, y: 10 * this.gridSize}
            ];
            
            // 生成食物
            this.generateFood();
            
            // 重置分数
            this.score = 0;
            
            // 绘制游戏
            this.drawGame();
        },
        startGame() {
            if (this.gameInterval) {
                clearInterval(this.gameInterval);
            }
            this.initGame();
            this.isPaused = false;
            this.gameInterval = setInterval(this.gameLoop, 150);
        },
        pauseGame() {
            this.isPaused = true;
            clearInterval(this.gameInterval);
        },
        resumeGame() {
            if (this.isPaused) {
                this.isPaused = false;
                this.gameInterval = setInterval(this.gameLoop, 150);
            }
        },
        restartGame() {
            this.startGame();
        },
        gameLoop() {
            this.direction = this.nextDirection;
            this.moveSnake();
            this.checkCollision();
            this.drawGame();
        },
        moveSnake() {
            const head = {...this.snake[0]};
            
            switch (this.direction) {
                case 'up':
                    head.y -= this.gridSize;
                    break;
                case 'down':
                    head.y += this.gridSize;
                    break;
                case 'left':
                    head.x -= this.gridSize;
                    break;
                case 'right':
                    head.x += this.gridSize;
                    break;
            }
            
            // 添加新头部
            this.snake.unshift(head);
            
            // 检查是否吃到食物
            if (head.x === this.food.x && head.y === this.food.y) {
                this.score += 10;
                if (this.score > this.highScore) {
                    this.highScore = this.score;
                }
                this.generateFood();
            } else {
                // 没吃到食物则移除尾部
                this.snake.pop();
            }
        },
        generateFood() {
            const maxPos = this.canvasSize / this.gridSize;
            this.food = {
                x: Math.floor(Math.random() * maxPos) * this.gridSize,
                y: Math.floor(Math.random() * maxPos) * this.gridSize
            };
            
            // 确保食物不会生成在蛇身上
            for (let segment of this.snake) {
                if (segment.x === this.food.x && segment.y === this.food.y) {
                    this.generateFood();
                    return;
                }
            }
        },
        checkCollision() {
            const head = this.snake[0];
            
            // 检查是否撞墙
            if (
                head.x < 0 || 
                head.y < 0 || 
                head.x >= this.canvasSize || 
                head.y >= this.canvasSize
            ) {
                this.gameOver();
                return;
            }
            
            // 检查是否撞到自己
            for (let i = 1; i < this.snake.length; i++) {
                if (head.x === this.snake[i].x && head.y === this.snake[i].y) {
                    this.gameOver();
                    return;
                }
            }
        },
        gameOver() {
            clearInterval(this.gameInterval);
            alert(`游戏结束！你的得分是: ${this.score}`);
        },
        drawGame() {
            // 清空画布
            this.ctx.clearRect(0, 0, this.canvasSize, this.canvasSize);
            
            // 绘制蛇
            this.ctx.fillStyle = 'green';
            for (let segment of this.snake) {
                this.ctx.fillRect(segment.x, segment.y, this.gridSize - 1, this.gridSize - 1);
            }
            
            // 绘制食物
            this.ctx.fillStyle = 'red';
            this.ctx.fillRect(this.food.x, this.food.y, this.gridSize - 1, this.gridSize - 1);
        },
        handleKeyPress(e) {
            if (this.isPaused) return;
            
            switch (e.key) {
                case 'ArrowUp':
                    if (this.direction !== 'down') this.nextDirection = 'up';
                    break;
                case 'ArrowDown':
                    if (this.direction !== 'up') this.nextDirection = 'down';
                    break;
                case 'ArrowLeft':
                    if (this.direction !== 'right') this.nextDirection = 'left';
                    break;
                case 'ArrowRight':
                    if (this.direction !== 'left') this.nextDirection = 'right';
                    break;
            }
        }
    }
}
</script>

<style scoped>
#snake {
    display: flex;
    flex-direction: column;
    align-items: center;
    font-family: Arial, sans-serif;
}

#game-canvas {
    border: 1px solid #000;
    margin: 20px 0;
}

.controls {
    margin-bottom: 20px;
}

.controls button {
    margin: 0 10px;
    padding: 8px 16px;
    font-size: 16px;
    cursor: pointer;
}

.scores {
    font-size: 18px;
    font-weight: bold;
}

#score {
    color: #333;
}

#high-score {
    color: #f00;
}
</style>
