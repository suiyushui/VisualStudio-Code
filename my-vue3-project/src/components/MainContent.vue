<template>
    <main>
      <Carousel />
      
      <ul class="navlist">
        <li v-for="(item, index) in navItems" :key="index">
          <img :src="item.image" :alt="item.alt">
          <p>{{ item.name }}</p>
        </li>
      </ul>
  
      <div class="haoke">
        <h4 class="hktitle">
          <img src="../assets/img/state.png" alt="">
          精彩好图
          <img src="../assets/img/state.png" alt="">
        </h4>
  
        <ol class="hklist">
          <li v-for="(item, index) in hkItems" :key="index">
            <img :src="item.mainImage" :alt="item.name">
            <p>{{ item.description }}</p>
            <div class="infoleft">
              <p>{{ item.fullName }}</p>
              <img :src="item.localImage" :alt="item.region">
              <p>{{ item.region }}</p>
            </div>
          </li>
        </ol>
      </div>
    </main>
  </template>
  
  <script>
  export default {
    name: 'MainContent',
    data() {
      return {
        navItems: [
          { image: require('../assets/img/img1.jpg'), alt: '图片1', name: '芙宁娜' },
          { image: require('../assets/img/img2.jpg'), alt: '图片2', name: '八重神子' },
          { image: require('../assets/img/img3.jpg'), alt: '图片3', name: '魈' },
          { image: require('../assets/img/img4.jpg'), alt: '图片4', name: '阿贝多' },
          { image: require('../assets/img/img5.jpg'), alt: '图片5', name: '温迪' },
          { image: require('../assets/img/img6.jpg'), alt: '图片6', name: '钟离' },
          { image: require('../assets/img/img7.jpg'), alt: '图片7', name: '枫原万叶' },
          { image: require('../assets/img/img8.jpg'), alt: '图片8', name: '神里绫人' },
          { image: require('../assets/img/img9.jpg'), alt: '图片9', name: '七七' },
          { image: require('../assets/img/img10.jpg'), alt: '图片10', name: '云堇' }
        ],
        hkItems: [
          { 
            mainImage: require('../assets/img/varesa.png'), 
            description: '悠悠哉哉，无比松弛的「沃陆之邦」战士兼果园主，喜欢充满力量的英雄，还有巨量美食！---悠暇豪劲',
            fullName: '全名/本名: 瓦雷莎',
            localImage: require('../assets/img/varesalocal.png'),
            region: '纳塔'
          },
          { 
            mainImage: require('../assets/img/Mizuki.png'), 
            description: '「秋沙钱汤」的股东，梦貘一族的心理诊疗师，致力于驱散噩梦，为人们带来安宁的心境。---绮梦缱绻',
            fullName: '全名/本名: 梦见月瑞希',
            localImage: require('../assets/img/Mizukilocal.png'),
            region: '稻妻'
          },
          { 
            mainImage: require('../assets/img/Mualani.png'), 
            description: '纳塔远近闻名的向导，水上用品商店的经营者，精通各类水上运动的逐浪客---哗啦啦逐浪客',
            fullName: '全名/本名: 玛拉妮',
            localImage: require('../assets/img/varesalocal.png'),
            region: '纳塔'
          },
          { 
            mainImage: require('../assets/img/Citlali.png'), 
            description: '烟谜主的大萨满，令所有族人敬畏的黑曜石奶奶。---白星黑曜',
            fullName: '全名/本名: 茜特菈莉',
            localImage: require('../assets/img/varesalocal.png'),
            region: '纳塔'
          }
        ]
      }
    }
  }
  </script>
  
  <style scoped src="../assets/css/index.css"></style>