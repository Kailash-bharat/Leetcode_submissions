class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    static const int mod = 1e9 + 7;
    vector<long long> fact, invfact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    void precompute(int n) {
        fact.resize(n + 1);
        invfact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        invfact[n] = power(fact[n], mod - 2);
        for (int i = n; i >= 1; i--) {
            invfact[i - 1] = invfact[i] * i % mod;
        }
    }

    long long nCr(int n, int r) {
        return fact[n] * invfact[r] % mod
             * invfact[n - r] % mod;
    }

public:
    Node* construct(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }

        if (data > root->val) {
            root->right = construct(root->right, data);
        } else {
            root->left = construct(root->left, data);
        }

        return root;
    }

    pair<int, long long> help(Node* root) {
        if (root == NULL) {
            return {0, 1};
        }

        auto [n1, a] = help(root->left);
        auto [n2, b] = help(root->right);

        int total = n1 + n2;

        long long ans = a * b % mod;
        ans = ans * nCr(total, n1) % mod;

        return {total + 1, ans};
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precompute(n);

        Node* root = new Node(nums[0]);

        for (int i = 1; i < n; i++) {
            construct(root, nums[i]);
        }

        long long ans = help(root).second;

        return (ans - 1 + mod) % mod;
    }
};
