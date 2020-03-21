#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

int log2ceil(int n) {
  --n;
  n |= n >> 16;
  n |= n >> 8;
  n |= n >> 4;
  n |= n >> 2;
  n |= n >> 1;
  return n + 1;
}

int log2ceil(long long n) {
  --n;
  n |= n >> 32;
  n |= n >> 16;
  n |= n >> 8;
  n |= n >> 4;
  n |= n >> 2;
  n |= n >> 1;
  return n + 1;
}

//Range Maximum Tree
struct RMaQ {
  using value_type = int;
  static value_type id() { return INT_MIN; }
  static value_type op(const value_type &l, const value_type &r) {
    return std::max(l, r);
  }
};

template <class Monoid> class SegmentTree {
    public:
    using value_type = typename Monoid::value_type;
    using update_type = typename Monoid::value_type;

    private:
    const int size_, n;
    std::vector<value_type> data;

    public:
    SegmentTree(const std::vector<value_type> &vec) :
        size_(vec.size()), n(log2ceil(size_)), data(n * 2, Monoid::id()) {
        std::copy(begin(vec), end(vec), begin(data) + n);
        for (int i = n - 1; i >= 0; --i) {
        data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
        }
    }

    SegmentTree(const int count, const value_type &value = Monoid::id()) :
        SegmentTree(std::vector<value_type>(count, value)) {}

    int size() const { return size_; }

    void update(int pos, const value_type &value) {
        assert(0 <= pos && pos < size_);  // assertion
        data[pos += n] = value;
        while (pos /= 2) {
        data[pos] = Monoid::op(data[pos * 2], data[pos * 2 + 1]);
        }
    }

    value_type query(int l, int r) const {
        assert(0 <= l && l <= r && r <= size_);  // assertion
        l += n;
        r += n;
        value_type res1 = Monoid::id(), res2 = Monoid::id();
        while (l < r) {
        if (l & 1) res1 = Monoid::op(res1, data[l++]);
        if (r & 1) res2 = Monoid::op(data[--r], res2);
        l >>= 1;
        r >>= 1;
        }
        return Monoid::op(res1, res2);
    }
};

class GoogleCodeJam
{
public:
    string case_prefix;
    void exec()
    {
        int n,k;
        cin>>n>>k;
        vector<int> c(n),d(n);
        for(int i = 0; i < n; i++)
        {
            cin>>c[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin>>d[i];
        }
        SegmentTree<RMaQ> segc(c), segd(d);
        ll ans=0;
        for(int l = 0; l < n; l++)
        {
            for(int r = l+1; r <= n; r++)
            {
                //scout<<l<<" "<<r<<" "<<segc.query(l,r)<<" "<<segd.query(l,r)<<endl;
                if(abs(segc.query(l,r)-segd.query(l,r))<=k)
                {
                    ans++;
                }
            }
            
        }
        

        cout<<ans<<endl;
    }
    GoogleCodeJam()
    {
        int T;
        std::cin >> T;
        for (int i = 1; i <= T; i++)
        {
            case_prefix = "Case #" + std::to_string(i) + ": ";
            cout << case_prefix;
            exec();
        }
    }
};

int main()
{
    GoogleCodeJam();

    return 0;
}