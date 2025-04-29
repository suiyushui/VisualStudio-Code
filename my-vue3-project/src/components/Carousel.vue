<template>
    <div class="carousel">
      <div class="carousel-slide">
        <div v-for="(slide, index) in slides" :key="index">
          <img :src="slide.image" :alt="slide.alt">
        </div>
      </div>
      <div class="carousel-controls">
        <button id="prev" @click="goToSlide(currentIndex - 1)">&#10094;</button>
        <button id="next" @click="goToSlide(currentIndex + 1)">&#10095;</button>
      </div>
      <div class="carousel-dots">
        <button 
          v-for="(dot, i) in dots" 
          :key="i" 
          :class="{ active: i === currentIndex }"
          @click="goToSlide(i)"
        ></button>
      </div>
    </div>
  </template>
  
  <script>
  export default {
    name: 'ImageCarousel',
    data() {
      return {
        currentIndex: 0,
        autoPlayInterval: null,
        isAutoPlaying: false,
        autoPlayDelay: 3000,
        slides: [
          { image: require('../assets/img/image1.jpg'), alt: '图片1' },
          { image: require('../assets/img/image2.jpg'), alt: '图片2' },
          { image: require('../assets/img/image3.jpg'), alt: '图片3' },
          { image: require('../assets/img/image4.jpg'), alt: '图片4' }
        ]
      }
    },
    computed: {
      dots() {
        return Array(this.slides.length).fill(null);
      }
    },
    mounted() {
      this.init();
    },
    beforeUnmount() {
      this.stopAutoPlay();
    // Clean up event listeners
    this.$el.removeEventListener('mouseenter', this.stopAutoPlay);
    this.$el.removeEventListener('mouseleave', this.startAutoPlay);
    },
    methods: {
      init() {
        this.updateSlidePosition();
        this.startAutoPlay();
        this.bindHoverEvents();
      },
      goToSlide(index) {
        this.currentIndex = (index + this.slides.length) % this.slides.length;
        this.updateSlidePosition();
        this.resetAutoPlay();
      },
      updateSlidePosition() {
        const offset = -this.currentIndex * 100;
        const slideElement = this.$el.querySelector('.carousel-slide');
        if (slideElement) {
          slideElement.style.transform = `translateX(${offset}%)`;
        }
      },
      startAutoPlay() {
        if (this.isAutoPlaying) return;
        
        this.isAutoPlaying = true;
        this.autoPlayInterval = setInterval(() => {
          this.goToSlide(this.currentIndex + 1);
        }, this.autoPlayDelay);
      },
      stopAutoPlay() {
        if (!this.isAutoPlaying) return;
        
        clearInterval(this.autoPlayInterval);
        this.isAutoPlaying = false;
      },
      resetAutoPlay() {
        this.stopAutoPlay();
        this.startAutoPlay();
      },
      bindHoverEvents() {
        this.$el.addEventListener('mouseenter', this.stopAutoPlay);
        this.$el.addEventListener('mouseleave', this.startAutoPlay);
      }
    }
  }
  </script>
  
  <style scoped src="../assets/css/carousel.css"></style>