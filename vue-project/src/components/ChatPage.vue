<template>
  <main class="mx-auto max-w-[780px] w-full h-screen overflow-y-auto px-5 bg-white text-black">
    <!-- 聊天消息列表 -->
    <div class="pb-24">
      <!-- AI消息气泡 -->
      <div v-for="(msg, index) in messages" :key="index" class="my-4">
        <div v-if="msg.role === 'ai'" class="flex justify-start">
          <div class="max-w-[80%] bg-white border border-gray-200 rounded-lg p-3">
            {{ msg.content }}
          </div>
        </div>
        <!-- 用户消息气泡 -->
        <div v-else class="flex justify-end">
          <div class="max-w-[80%] bg-blue-500 text-white rounded-lg p-3">
            {{ msg.content }}
          </div>
        </div>
      </div>
    </div>

    <!-- 输入区域 -->
    <div class="fixed bottom-5 left-0 right-0 px-5">
      <div class="max-w-[780px] mx-auto border border-gray-200 rounded-lg bg-white p-2 flex items-end">
        <textarea
          v-model="inputMessage"
          placeholder="你有什么要我帮助的吗？"
          class="flex-1 outline-none resize-none p-2"
          rows="1"
          @keydown.enter.exact.prevent="sendMessage"
        />
        <button
          @click="sendMessage"
          class="bg-blue-500 text-white p-2 rounded-lg ml-2"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <line x1="22" y1="2" x2="11" y2="13"></line>
            <polygon points="22 2 15 22 11 13 2 9 22 2"></polygon>
          </svg>
        </button>
      </div>
    </div>
  </main>
</template>

<script setup lang="ts">
import { ref } from 'vue';

const inputMessage = ref('');
const messages = ref<Array<{role: 'user' | 'ai', content: string}>>([]);

const sendMessage = () => {
  if (inputMessage.value.trim()) {
    messages.value.push({
      role: 'user',
      content: inputMessage.value
    });
    inputMessage.value = '';
    
    // 模拟AI回复
    setTimeout(() => {
      messages.value.push({
        role: 'ai',
        content: '这是AI的回复'
      });
    }, 500);
  }
};
</script>