# #python通过try-except-else-finally语句来处理异常。
# # 捕获可能出错的代码,定义错误发生时的处理方式
# def risky_operation():
#     pass
# def no_error_operation():
#     pass
# def cleanup_resources():
#     pass
# try:
#     # 可能发生异常的代码块
#     risky_operation()
# except SpecificErrorType1 as e:
#     # 捕获特定类型的异常并处理（e是异常对象）
#     handle_error1(e)
# except (SpecificErrorType2, SpecificErrorType3) as e:
#     # 同时捕获多种异常
#     handle_errors2_3(e)
# else:
#     # 当try块无异常时执行（可选）
#     no_error_operation()
# finally:
#     # 无论是否有异常，都会执行（常用于资源清理，可选）
#     cleanup_resources()



def parse_data(line):
    # 栈帧3 (parse_data)
    try:
        value = int(line.strip())  # 假设这里 line 是 "abc", 引发 ValueError
        return value * 2
    except TypeError:  # 不匹配 ValueError!
        print("Got a TypeError in parse_data")
    except ValueError:  # 匹配 ValueError!
        print("Got a ValueError in parse_data")

def read_file(filename):
    # 栈帧2 (read_file)
    data = []
    with open(filename) as f:  # 'with' 语句隐含了异常处理和资源清理
        for line in f:
            try:
                num = parse_data(line)  # 这里调用 parse_data
                data.append(num)
            except ValueError:  # 这个 except 在 read_file 栈帧
                print(f"Skipping invalid line: {line.strip()}")
    return data

# 栈帧1 (main/module)
if __name__ == "__main__":
    # 没有 try-except 覆盖下面的调用
    results = read_file("data.txt")  # 这里调用 read_file
    print(results)