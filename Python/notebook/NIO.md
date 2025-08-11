# **Java NIO (New I/O) 详解**

Java NIO（New I/O）是 Java 1.4 引入的高性能 I/O API，相比传统的 `java.io`（BIO，Blocking I/O），它提供了**非阻塞 I/O**、**通道（Channel）**和**缓冲区（Buffer）**等机制，适用于高并发网络编程和文件操作。

---

## **1. NIO 核心组件**
### **(1) Buffer（缓冲区）**
- 用于暂存数据，是 NIO 读写数据的中转站。
- 主要实现类：
  - `ByteBuffer`（最常用）
  - `CharBuffer`、`IntBuffer`、`LongBuffer` 等（基本类型 Buffer）
- **重要属性**：
  - `capacity`：缓冲区最大容量（创建后不可变）。
  - `position`：当前读写位置。
  - `limit`：可操作数据的上限。
  - `mark`：标记位置，用于 `reset()`。

**示例：Buffer 基本使用**
```java
ByteBuffer buffer = ByteBuffer.allocate(1024); // 分配 1024 字节

buffer.put("Hello".getBytes()); // 写入数据
buffer.flip(); // 切换为读模式（limit=position, position=0）

while (buffer.hasRemaining()) {
    System.out.print((char) buffer.get()); // 逐个字节读取
}
buffer.clear(); // 清空缓冲区（position=0, limit=capacity）
```

---

### **(2) Channel（通道）**
- 类似于传统 I/O 的 `InputStream`/`OutputStream`，但支持**双向读写**。
- 主要实现类：
  - `FileChannel`（文件操作）
  - `SocketChannel`（TCP 客户端）
  - `ServerSocketChannel`（TCP 服务端）
  - `DatagramChannel`（UDP）

**示例：文件复制（FileChannel）**
```java
try (FileChannel src = FileChannel.open(Paths.get("source.txt"));
     FileChannel dest = FileChannel.open(Paths.get("dest.txt"), StandardOpenOption.CREATE, StandardOpenOption.WRITE)) {
    src.transferTo(0, src.size(), dest); // 高效文件复制
}
```

---

### **(3) Selector（选择器）**
- 用于**多路复用**（单线程管理多个 Channel），实现非阻塞 I/O。
- 核心方法：
  - `Selector.open()`：创建选择器。
  - `channel.register(selector, ops)`：注册 Channel 到 Selector。
  - `selector.select()`：监听就绪的 Channel。

**示例：非阻塞 Echo 服务器**
```java
Selector selector = Selector.open();
ServerSocketChannel serverChannel = ServerSocketChannel.open();
serverChannel.bind(new InetSocketAddress(8080));
serverChannel.configureBlocking(false); // 非阻塞模式
serverChannel.register(selector, SelectionKey.OP_ACCEPT); // 监听连接事件

while (true) {
    selector.select(); // 阻塞直到有事件就绪
    Set<SelectionKey> keys = selector.selectedKeys();
    for (SelectionKey key : keys) {
        if (key.isAcceptable()) { // 新连接
            SocketChannel client = serverChannel.accept();
            client.configureBlocking(false);
            client.register(selector, SelectionKey.OP_READ);
        } else if (key.isReadable()) { // 可读数据
            SocketChannel client = (SocketChannel) key.channel();
            ByteBuffer buffer = ByteBuffer.allocate(1024);
            client.read(buffer);
            buffer.flip();
            client.write(buffer); // Echo 回传
        }
    }
    keys.clear();
}
```

---

## **2. NIO vs BIO（传统 I/O）**
| 特性               | **BIO（java.io）**           | **NIO（java.nio）**          |
|--------------------|-----------------------------|-----------------------------|
| **阻塞/非阻塞**     | 阻塞（线程等待 I/O 完成）     | 非阻塞（可轮询或事件驱动）    |
| **数据传输单位**    | 流（Stream）                | 缓冲区（Buffer）             |
| **通道方向**        | 单向（Input/Output）        | 双向（Channel 可读可写）     |
| **多路复用**        | 不支持（需多线程）           | 支持（Selector）             |
| **适用场景**        | 低并发、简单 I/O            | 高并发（如聊天服务器、文件传输） |

---

## **3. 进阶特性**
### **(1) Scatter/Gather（分散/聚集）**
- **Scatter**：从 Channel 读取数据到多个 Buffer。
- **Gather**：将多个 Buffer 的数据写入 Channel。

```java
ByteBuffer header = ByteBuffer.allocate(128);
ByteBuffer body = ByteBuffer.allocate(1024);

ByteBuffer[] buffers = {header, body};
channel.read(buffers); // Scatter 读取

channel.write(buffers); // Gather 写入
```

### **(2) 内存映射文件（Memory-Mapped File）**
- 通过 `FileChannel.map()` 将文件直接映射到内存，提升大文件读写性能。
```java
FileChannel channel = FileChannel.open(Paths.get("largefile.dat"), StandardOpenOption.READ);
MappedByteBuffer buffer = channel.map(FileChannel.MapMode.READ_ONLY, 0, channel.size());
while (buffer.hasRemaining()) {
    System.out.print((char) buffer.get());
}
channel.close();
```

---

## **4. 总结**
- **NIO 适用于高并发、低延迟场景**（如 Netty、Kafka 等框架底层使用 NIO）。
- **BIO 更简单，适合传统 I/O 操作**（如文件读写、低并发网络通信）。
- **Selector + Channel + Buffer 是 NIO 的核心**，掌握它们可以优化 I/O 密集型应用。

如果想深入某个部分（如 Netty 的 NIO 优化），可以进一步探讨！