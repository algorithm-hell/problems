#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Point { int row, col; };
struct Range { int min, max; };
struct Area { Range row, col; } ;

class Lock {
public:
    Lock(vector<vector<int>>& lock): lock(lock) {}
    
    // 자물쇠 홈의 개수를 센다.
    int countHoles() {
        if (holes >= 0) return holes;
        
        int cnt = 0;
        for (int r=0; r<size(); r++) {
            for (int c=0; c<size(); c++) {
                if (lock[r][c] == 0) cnt++;
            }
        }
        
        holes = cnt;
        return holes;
    }
    
    int get(const Point& p) { return lock[p.row][p.col]; }
    int size() { return lock.size(); }
    
private:
    vector<vector<int>> lock;
    int holes = -1;
};

class Key {
public:
    Key(vector<vector<int>> key): key(key) {}
    
    // 시계방향으로 90도 회전시킨다.
    void rotate() {
        vector<vector<int>> rotated(key);
        
        for (int r=0; r<size(); r++) {
            int targetCol = (size()-1)-r;
            for (int c=0; c<size(); c++) {
                rotated[c][targetCol] = key[r][c];
            }
        }
        
        for (int r=0; r<size(); r++) {
            for (int c=0; c<size(); c++) {
                key[r][c] = rotated[r][c];
            }
        }
    }
    
    int get(const Point& p) { return key[p.row][p.col]; }  
    int size() { return key.size(); }
private:
    vector<vector<int>> key;
};

class Solver {
public:
    Solver(Lock& lock, Key& key): lock(lock), key(key) {};
    
    // 주어진 열쇠를 위, 아래, 양옆으로 이동시키면서
    // 자물쇠에 맞는지 검사한다.
    bool tryOpen() {
        for (int r=0; r<size(); r++) {
            for (int c=0; c<size(); c++) {
                Area overlap = getOverlap(r, c);
                
                int matched = tryMatch(Point{r, c}, overlap);
                if (matched == lock.countHoles()) return true;
            }
        }
        
        return false;
    }
    
    // 주어진 영역에서 자물쇠와 열쇠를 맞춰보고 맞춘 홈의 개수를 반환한다.
    int tryMatch(const Point p, const Area& overlap) {
        int matched = 0;
        
        for (int r=overlap.row.min; r<=overlap.row.max; r++) {
            for (int c=overlap.col.min; c<=overlap.col.max; c++) {
                Point pLock = Point{r-key.size()+1, c-key.size()+1};
                Point pKey = Point{r-p.row, c-p.col};
                
                if (key.get(pKey) == lock.get(pLock)) return matched;
                if (key.get(pKey) == 1) matched++;
            }
        }
        
        return matched;
    }
    
    void rotateKey() { key.rotate(); }
    
    // 자물쇠와 열쇠를 한 공간에 둔 좌표체계의 크기를 반환한다.
    int size() { return lock.size() + key.size() - 1; }
    
    // 좌표 (r, c)에서 자물쇠와 열쇠가 겹치는 영역을 구한다.
    Area getOverlap(int r, int c) {
        return Area{
            Range{
                max(r, key.size()-1),
                min(r+key.size()-1, size()-1)
            },
            Range{
                max(c, key.size()-1),
                min(c+key.size()-1, size()-1)
            }
        };
    }
    
private:
    Lock& lock;
    Key& key;
};

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    Lock myLock(lock);
    Key myKey(key);
    Solver solver(myLock, myKey);
    
    for (int i=0; i<4; i++) {
        bool solved = solver.tryOpen();
        if (solved) return true;
        
        solver.rotateKey();
    }
    
    return false;
}