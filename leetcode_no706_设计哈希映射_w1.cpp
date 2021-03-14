/* ------------------------------------------------------------------|
不使用任何内建的哈希表库设计一个哈希映射（HashMap）。

实现 MyHashMap 类：

MyHashMap() 用空映射初始化对象
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
 

示例：

输入：
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
输出：
[null, null, null, 1, -1, null, 1, null, -1]

解释：
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
 

提示：

0 <= key, value <= 106
最多调用 104 次 put、get 和 remove 方法
 

进阶：你能否不使用内置的 HashMap 库解决此问题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashmap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*  
*
*	执行用时：136 ms, 在所有 C++ 提交中击败了73.61%的用户
*	内存消耗：51.2 MB, 在所有 C++ 提交中击败了41.78%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> ways(n, 0);
    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) {
        return 0;
    }

    ways[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j]) {
                ways[j] = 0;
                continue;
            }
            if (j == 0) {
                continue;
            }
            else {
                ways[j] += ways[j - 1];
            }
        }
    }
    return ways[n - 1];
}

class MyHashMap {
private:
    vector<list<pair<int, int>>> l;
    static const int hashkey = 443;
    const int num(int& key) {
        return key % hashkey;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() :l(hashkey){}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int tmp = num(key);
        for (auto iter = l[tmp].begin(); iter != l[tmp].end(); ++iter) {
            if ((*iter).first == key) {
                (*iter).second = value;
                return;
            }
        }
        l[tmp].push_back(pair<int, int>{ key,value });
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int tmp = num(key);
        for (auto iter = l[tmp].begin(); iter != l[tmp].end(); ++iter) {
            if ((*iter).first == key) {
                return (*iter).second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int tmp = num(key);
        for (auto iter = l[tmp].begin(); iter != l[tmp].end(); ++iter) {
            if ((*iter).first == key) {
                l[tmp].remove(*iter);
                return;
            }
        }
    }
};

int main() {    
    vector<int> tmp(10, 0);
}