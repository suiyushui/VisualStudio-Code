import { createRouter, createWebHistory } from 'vue-router';
import Hello from '../components/Hello.vue';
import Movie from '../components/Movie.vue';
import Email from '../components/Email.vue';
import BullsAndCows from '../components/BullsAndCows.vue';
import Snake from '../components/Snake.vue';
import New_project from '../components/new_project.vue';

const routes = [
    { path: '/New_project', component: New_project },
    { path: '/Hello', component: Hello,children:[
        { path: 'bullsAndCows', component: BullsAndCows },
        { path: 'snake', component: Snake }
    ]},
    { path: '/Movie', component: Movie },
    { path: '/Email', component: Email },
];

const router = createRouter({
    history: createWebHistory(),
    routes
});

export default router;