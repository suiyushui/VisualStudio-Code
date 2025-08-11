# import time
# import multiprocessing

# def sing():
#     for i in range(3):
#         print('唱歌...')
#         time.sleep(0.5)

# def dance():
#     for i in range(3):
#         print('跳舞...')
#         time.sleep(0.5)


# if __name__ == '__main__':
#     """
#         # 单进程实现函数调用
#         sing()
#         dance()
#     """
#     # 多进程实现函数调用
#     sing_processing = multiprocessing.Process(target=sing)
#     dance_processing = multiprocessing.Process(target=dance)
#     sing_processing.start()
#     dance_processing.start()


# import time
# import multiprocessing
# import os

# def task():
#     for i in range(3):
#         # 。getid()方法获取当前进程的ID
#         print(f'进程{os.getpid()}正在执行任务...')
#         time.sleep(0.5)
# if __name__ == '__main__':
#     """
#         # 单进程实现函数调用
#         task()
#     """
#     # 多进程实现函数调用
#     task_processing = multiprocessing.Process(target=task)
#     task_processing.start()
#     task_processing.join()
#     print('主进程执行完毕')



import time
import multiprocessing
import os

def copy_task(file_name,source_name,target_name):
    file_path_source=source_name+'\\'+file_name
    file_path_target=target_name+'\\'+file_name
    with open(file_path_source,'rb') as f_source:
        with open(file_path_target,'wb') as f_target:
            while True:
                data=f_source.read(1024)
                if not data:
                    break
                f_target.write(data)
    print(f'{file_name}文件复制完成')

if __name__=='__main__':
    source_name='壁纸'
    target_name='test_copy'
    if not os.path.exists(target_name):
        os.makedirs(target_name)
    
    file_list=os.listdir(source_name)
    print(file_list)
    start_time=time.time()
    for file_name in file_list:
        sub_process=multiprocessing.Process(target=copy_task,args=(file_name,source_name,target_name))
        sub_process.start()
    end_time=time.time()
    print(f'总共耗时{end_time-start_time}秒')
