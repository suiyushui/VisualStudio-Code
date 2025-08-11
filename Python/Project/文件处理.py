import os

# 通用文件处理函数：接收目录和回调函数作为参数
def process_files(directory, callback):
    """
    处理指定目录下的所有文本文件
    :param directory: 要处理的目录
    :param callback: 处理文件内容的回调函数
    """
    # 遍历目录中的所有文件
    for filename in os.listdir(directory):
        # 只处理txt文件
        if filename.endswith('.txt'):
            file_path = os.path.join(directory, filename)
            try:
                # 读取文件内容
                with open(file_path, 'r', encoding='utf-8') as file:
                    content = file.read()
                # 调用回调函数处理内容，并获取结果
                result = callback(filename, content)
                print(f"处理 {filename} 完成: {result}")
            except Exception as e:
                print(f"处理 {filename} 出错: {str(e)}")

# 回调函数1：统计文件字数
def count_words(filename, content):
    word_count = len(content.split())
    return f"共 {word_count} 个单词"

# 回调函数2：查找关键词
def find_keyword(keyword):
    # 这里使用了闭包，让回调函数可以携带额外参数
    def callback(filename, content):
        count = content.count(keyword)
        return f"关键词 '{keyword}' 出现了 {count} 次"
    return callback

# 回调函数3：备份文件到指定目录
def backup_file(backup_dir):
    os.makedirs(backup_dir, exist_ok=True)
    def callback(filename, content):
        backup_path = os.path.join(backup_dir, filename)
        with open(backup_path, 'w', encoding='utf-8') as file:
            file.write(content)
        return f"已备份到 {backup_dir}"
    return callback

# 使用示例
if __name__ == "__main__":
    target_dir = "documents"  # 假设我们有一个documents目录存放txt文件
    
    print("=== 统计文件字数 ===")
    process_files(target_dir, count_words)
    
    print("\n=== 查找关键词 'python' ===")
    process_files(target_dir, find_keyword("python"))
    
    print("\n=== 备份文件 ===")
    process_files(target_dir, backup_file("documents_backup"))
