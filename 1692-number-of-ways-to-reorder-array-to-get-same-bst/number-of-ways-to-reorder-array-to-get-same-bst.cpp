// typedef unsigned long long llu;

// class Node {
//     public:

//     Node* left = NULL;
//     Node* right = NULL;
//     int val;

//     Node(int v) {
//         val = v;
//     }

//     void add(int v) {
//         if (v < val) {
//             if (left) left->add(v);
//             else left = new Node(v);
//         } else if (v > val) {
//             if (right) right->add(v);
//             else right = new Node(v);
//         }
//     }
// };

// class Solution {
// private:
    
//     struct Info {
//         llu size;
//         llu ways;

//         Info(llu s, llu w) {
//             size = s;
//             ways = w;
//         }
//     };

//     /** Returns <tree size, ways> for the (sub)tree represented by node */
//     Info helper(Node* node, llu mod) {
//         if (node->left && node->right) {
//             Info l = helper(node->left, mod);
//             Info r = helper(node->right, mod);

//             llu ways = chooseMod(l.size + r.size, l.size, mod);
//             ways = (ways * l.ways) % mod;
//             ways = (ways * r.ways) % mod;
//             printf("%i: size=%llu, ways=%llu\n", node->val, 1+l.size+r.size, ways);
//             return Info(1+l.size+r.size, ways);
//         } else if (node->left) {
//             Info l = helper(node->left, mod);
//             printf("%i: size=%llu, ways=%llu\n", node->val, 1+l.size, l.ways);
//             return Info(1+l.size, l.ways);
//         } else if (node->right) {
//             Info r = helper(node->right, mod);
//             printf("%i: size=%llu, ways=%llu\n", node->val, 1+r.size, r.ways);
//             return Info(1+r.size, r.ways);
//         } else {
//             printf("%i: size=%llu, ways=%llu (LEAF)\n", node->val, 1, 1);
//             return Info(1, 1);
//         }
//     }

//     // returns (n choose r) % mod
//     llu chooseMod(llu n, llu r, llu mod) {
//         // llu rr = min(r, n-r);
//         // // we need n choose r = n!/(r! * (n-r)!) = n*(n-1)*..*(n-r+1) / r!
//         // // r = 0: 1
//         // // r = 1: n
//         // // r = 2: n*(n-1) / 2
//         // // r = 3: n*(n-1)*(n-2) / 2 / 3
//         // llu res = 1;
//         // for (llu k = 1; k <= rr; ++k) {
//         //     res *= (n+1-k);
//         //     res /= k;
//         // }
//         // printf("%llu choose %llu mod %llu is %llu\n", n, r, mod, res);
//         // return res % mod;
//         return nCr[n][r];
//     }

//     vector<vector<int>> nCr; // pascal's triangle % mod

// public:

//     int numOfWays(vector<int>& nums) {
//         llu mod = 1000000000L + 7L;

//         // init triangle
//         nCr.push_back({1});
//         nCr.push_back({1, 1});
//         for (int n = 2; n <= nums.size(); ++n) {
//             nCr.push_back({1}); // n choose 0
//             for (int k = 1; k < n; ++k) nCr.back().push_back((nCr[n-1][k-1] + nCr[n-1][k]) % mod);
//             nCr.back().push_back(1); // n choose n
//         }

//         Node* root = new Node(nums[0]);
//         for (llu i = 1L; i < nums.size(); ++i) root->add(nums[i]); // O(n) space, O(n*log(n)) time
        
//         // kind of brute force: create a BST from nums
//         // then traverse the tree to find the number of ways
//         // leaf: one way
//         // node with one child: had to add this node before child, so ways(child)
//         // node with two children: add parent, then children
//         //    we have to add |left| + |right| nodes
//         //    and there are wL = ways(left) and wR = ways(right) for the children
//         // can add all left, then all right: wL * wR
//         // can add all 1 left, all right, then remaining left: wL * wR again?
//         //    wL permutations of left elements, wR permutations of right elements
//         //    then of the C === |left| + |right| insert operations, there are (C choose |left|) == (C choose |right|) ways
//         //    to interleave left and right elements
//         // so (C choose |left|) * wL * wR total ways

//         Info info = helper(root, mod);
//         return (info.ways-1) % mod;
//     }
// };

// // FIXME: ugh had to CHEAT, combinatorics were blowing up. Solutions are
// //           compute pascal's triangle, all possible c choose k we could encounter (O(n**2))
// //           OR multiplicative modular inverse: want inv = 1/den modulo mod
// //              such that we can compute num * inv modulo mod

constexpr int mod = 1'000'000'007;
int fact[1001], ifact[1001];

long pow(long u, int p) {
    long res = 1;
    while (p) {
        if (p & 1) res = res * u % mod;
        p >>= 1;
        u = u * u % mod;
    }
    return res;
}

int speedup = []{
    ios::sync_with_stdio(0); cin.tie(0);
    long f = fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1000; ++i) fact[i] = f = f * i % mod;
    ifact[1000] = f = pow(f, mod - 2);
    for (int i = 1000; i; --i) ifact[i-1] = f = f * i % mod;
    return 0;
}();


int mi[10][1000], mp[10][1000];

int compute(int l, int r) {
    int sz = r - l;
    if (sz <= 2) return 1;
    int lsz = 31 - __builtin_clz(sz), r2 = r - (1 << lsz);
    int p = mi[lsz][l] <= mi[lsz][r2] ? mp[lsz][l] : mp[lsz][r2];

    long res = long(fact[sz-1]) * ifact[p-l] % mod * ifact[r-p-1] % mod;
    return res * compute(l, p) % mod * compute(p+1, r) % mod;
}

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = size(nums), pos[n+1];
        for (int i = 0; i < n; ++i) pos[nums[i]]  = i;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; ++i) mi[0][i] = pos[nums[i]], mp[0][i] = i;
        for (int d = 0, s = 2; s <= n; ++d, s *= 2) {
            for (int i = 0; i + s <= n; ++i) {
                int j = i + s/2;
                if (mi[d][i] <= mi[d][j]) j = i;
                mi[d+1][i] = mi[d][j];
                mp[d+1][i] = mp[d][j];
            }
        }
        return compute(0, n) - 1;
    }
};