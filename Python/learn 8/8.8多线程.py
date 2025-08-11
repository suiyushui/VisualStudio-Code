import threading

class MyThread(threading.Thread):
    def run(self):
        self.name="MyThread"
        print(threading.current_thread().name)
        print(threading.current_thread().ident)
    

my_thread = MyThread()
my_thread.start()
my_thread.join()