import { createRouter, createWebHistory } from 'vue-router';

const routes = [
  { 
    path: '/new-project', 
    name: 'NewProject',
    component: () => import('../components/new_project.vue'),
    // 统一使用kebab-case命名路由路径
    alias: '/New_Project' // 兼容旧路径
  },
  { 
    path: '/hello', 
    name: 'Hello',
    component: () => import('../components/Hello.vue'),
    children: [
      { 
        path: 'bulls-and-cows', 
        name: 'BullsAndCows',
        component: () => import('../components/BullsAndCows.vue') 
      },
      { 
        path: 'snake', 
        name: 'Snake',
        component: () => import('../components/Snake.vue') 
      }
    ]
  },
  { 
    path: '/movie', 
    name: 'Movie',
    component: () => import('../components/Movie.vue') 
  },
  { 
    path: '/email', 
    name: 'Email',
    component: () => import('../components/Email.vue') 
  },
  {
    path: '/',
    redirect: { name: 'Hello' } // 使用命名路由更可靠
  },
  {
    path: '/:pathMatch(.*)*',
    redirect: '/' // 添加404处理
  }
];

const router = createRouter({
  history: createWebHistory(),
  routes,
  // 统一路由行为配置
  scrollBehavior(to, from, savedPosition) {
    return savedPosition || { top: 0 }
  }
});
// 导出router实例
// 这样可以在main.js中直接使用router实例
export default router;