import random
import threading
import time
from typing import Any, Dict, Type, TypeVar, final

T = TypeVar('T', bound='Singleton')

@final
class Singleton:
    """
    线程安全的单例基类，使用双重检查锁定模式实现
    支持继承和多线程环境
    """
    
    _instances: Dict[Type['Singleton'], 'Singleton'] = {}  # 存储所有单例类的实例
    _lock: threading.RLock = threading.RLock()  # 可重入锁，确保线程安全
    
    def __init__(self, *args: Any, **kwargs: Any) -> None:
        """
        初始化方法，模拟耗时操作
        """
        time.sleep(random.random() * 0.1)  # 模拟初始化耗时
        self._initialized = True  # 标记是否已初始化
        
    @classmethod 
    def instance(cls: Type[T], *args: Any, **kwargs: Any) -> T:
        """
        获取单例实例的类方法
        使用双重检查锁定确保线程安全
        """
        # 第一重检查 - 无锁快速路径
        if cls not in cls._instances:
            with cls._lock:
                # 第二重检查 - 确保只有一个线程能创建实例
                if cls not in cls._instances:
                    # 使用object.__new__避免递归调用
                    instance = super(Singleton, cls).__new__(cls)
                    instance.__init__(*args, **kwargs)
                    cls._instances[cls] = instance
        return cls._instances[cls]  # type: ignore
    
    @classmethod
    def clear_instance(cls) -> None:
        """
        清除单例实例（主要用于测试）
        """
        with cls._lock:
            if cls in cls._instances:
                del cls._instances[cls]
    
    @classmethod 
    def get_instance_count(cls) -> int:
        """
        获取当前已创建的单例数量（用于测试）
        """
        return len(cls._instances)
    
    def __new__(cls: Type[T], *args: Any, **kwargs: Any) -> T:
        """
        重写__new__防止直接实例化
        """
        if cls._instances.get(cls) is None:
            raise RuntimeError(
                f"{cls.__name__} must be instantiated using the instance() class method"
            )
        return cls._instances[cls] # type: ignore

def task() -> None:
    """
    测试任务函数，多个线程会调用此函数获取单例
    """
    obj = Singleton.instance()
    if obj:
        print(f'{obj}\tSingleton count: {Singleton.get_instance_count()}')

if __name__ == '__main__':
    # 测试代码
    print("=== 单线程测试 ===")
    Singleton.clear_instance()  # 确保测试环境干净
    
    s1 = Singleton.instance()
    s2 = Singleton.instance()
    print(f"s1 is s2: {s1 is s2}")  # 应该输出 True
    print(f"Instance count: {Singleton.get_instance_count()}")  # 应该输出 1
    
    try:
        # 尝试直接实例化应该抛出异常
        s3 = Singleton()
    except RuntimeError as e:
        print(f"Expected error when direct instantiation: {e}")
    
    print("\n=== 多线程测试 ===")
    Singleton.clear_instance()  # 重置测试环境
    
    # 创建并启动多个线程测试单例
    threads = []
    for i in range(5):  # 创建5个线程
        t = threading.Thread(target=task)
        threads.append(t)
        t.start()
    
    # 等待所有线程完成
    for t in threads:
        t.join()
    
    print(f"\nFinal instance count: {Singleton.get_instance_count()}")  # 应该输出 1