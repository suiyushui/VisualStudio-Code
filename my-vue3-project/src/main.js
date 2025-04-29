import { createApp } from 'vue'
import App from './App.vue'
import '@fortawesome/fontawesome-free/css/all.css'

// 创建应用实例
const app = createApp(App)

// 配置
app.config.productionTip = false

// 挂载应用
app.mount('#app')