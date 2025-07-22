
from queue import Queue
import threading, time, random,logging

logging.basicConfig(level=logging.INFO,format='%(message)s')
message_queue= Queue(maxsize=10)

def producer(producer_id):
    for i in range(4):
        message=f"生产者{producer_id}的消息{i}"
        message_queue.put(message)
        logging.info(f"生产者{producer_id},发送消息{message}")
        time.sleep(random.uniform(0.1,0.5))
    message_queue.put(None)

def consumer(consumer_id):
    while True:
        message=message_queue.get()
        if message is None:
            message_queue.put(None)
            break

        logging.info(f"消费者{consumer_id},接收消息{message}")
        message_queue.task_done()
        time.sleep(random.uniform(0.2,0.6))

if __name__=='__main__':
    Producers=[
        threading.Thread(target=producer,args=(1,)),
        threading.Thread(target=producer,args=(2,))
    ]
    Consumers=[
        threading.Thread(target=consumer,args=(1,)),
        threading.Thread(target=consumer,args=(2,)),
        threading.Thread(target=consumer,args=(3,))
    ]

    for p in Producers: 
        p.start()
    for c in Consumers:
        c.start()
    for p in Producers:
        p.join()
    message_queue.join()
    try:
        while True:
            message_queue.get_nowait()
            message_queue.task_done()
    except:
        pass
    for c in Consumers:
        c.join()
    logging.info("所有消息都已消费完毕")
    
