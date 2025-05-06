# 🔁 LRU Cache - DSA Project in C++

This project implements a **Least Recently Used (LRU) Cache** using C++ for efficient memory management. It utilizes a combination of **Hash Map** and **Doubly Linked List** to achieve constant time (`O(1)`) complexity for both `get()` and `put()` operations.

---

## 📌 Project Highlights

- Language: **C++**
- DSA Concepts: **Hash Map**, **Doubly Linked List**
- Time Complexity: `O(1)` for both `get` and `put`
- Suitable for: SDE Interviews, DSA practice, System Design basics

---

## 🚀 How it Works

- `put(key, value)`: Inserts or updates the value in the cache.
  - If the cache exceeds its capacity, the **least recently used** item is evicted.
- `get(key)`: Returns the value of the key if it exists, otherwise returns `-1`.
  - This operation also updates the usage to mark the key as most recently used.

---

## 🛠️ How to Run

1. **Clone the repo:**

   ```bash
   git clone https://github.com/shivamrshi/dsa-lru-cache.git
   cd dsa-lru-cache
   ```

2. **Compile and Run:**
   ```bash
   g++ LRUCache.cpp -o lru
   ./lru
   ```

---

## 📄 Sample Output

```bash
Get 2: 20
Get 1 (should be -1): -1
Get 3: 30
```

---

## 💡 Learning Outcomes

- Understanding real-world cache systems (like in web browsers or operating systems)
- Mastery of custom data structures in C++
- Applying object-oriented principles to DSA

---

## 📚 References

- [GeeksforGeeks - LRU Cache](https://www.geeksforgeeks.org/lru-cache-implementation/)
- [Leetcode - LRU Cache Problem](https://leetcode.com/problems/lru-cache/)

---

## ✅ To Do

- [ ] Add unit tests
- [ ] Extend to thread-safe version
- [ ] Add benchmarking tools

---

## 📬 Contact

Made with ❤️ by [Your Name](https://github.com/shivamrshi)  
Feel free to connect for collaborations!
