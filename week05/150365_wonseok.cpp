#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum Dir {
    UP, DOWN, LEFT, RIGHT
};

struct Direction {
    Dir dir;
    char letter;
};

class Point {
public:
    Point(int r, int c): row(r), col(c) {};

    Point get(Dir dir) { 
        switch (dir) {
            case DOWN:
                return down();
            case LEFT:
                return left();
            case RIGHT:
                return right();
            case UP:
                return up();
        };

        return Point(row, col);
    }

    Point left() { return Point(row, col-1); }
    Point right() { return Point(row, col+1); }
    Point up() { return Point(row-1, col); }
    Point down() { return Point(row+1, col); }

    int row, col;
};

class Maze {
public:
    Maze(int rows, int cols): rows(rows), cols(cols) {
        maze = vector<vector<char>>(
            rows+1, 
            vector<char>(cols+1, '.')
        );
    }

    void setEnd(int row, int col) {
        maze[row][col] = 'E';
        end = Point(row, col);
    }

    string search(int row, int col, int length) {
        string answer = "";
        bool found = _search(Point(row, col), answer, 0, length);
        return (found) ? answer : "impossible";
    }
    
private:
    bool _search(Point p, string& answer, int depth, int maxDepth) {
        // 탈출조건: 목표 길이 도달
        if (depth == maxDepth) {
            if (maze[p.row][p.col] == 'E') {
                this->answer = answer;
                return true;
            }
            else return false;
        }
        
        int remainingMoves = maxDepth - depth;
        int distance = getDistance(p, this->end);
        // 탈출조건: 최단 경로 도달 불가
        if (distance > remainingMoves)
            return false;
        // 탈출조건: 짝수, 홀수 불일치
        if (distance % 2 != remainingMoves % 2)
            return false;
        
        for (Direction& dir : dirs) {
            Point next = p.get(dir.dir);
            if (isOutofBound(next)) continue;

            answer += dir.letter;
            bool found = _search(next, answer, depth+1, maxDepth);
            if (found) return true;

            answer.pop_back();
        }

        return false;
    }

    bool isOutofBound(const Point& p) {
        return (p.row > rows || p.col > cols) ||
            (p.row <= 0 || p.col <= 0);
    }

    int getDistance(const Point& p1, const Point& p2) {
        return abs(p1.row-p2.row) + abs(p1.col-p2.col);
    }

    vector<vector<char>> maze;
    vector<Direction> dirs = {
        Direction{DOWN, 'd'},
        Direction{LEFT, 'l'},
        Direction{RIGHT, 'r'},
        Direction{UP, 'u'}
    };
    Point end = Point(0, 0);

    int rows, cols;
    string answer;
};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    Maze maze(n, m);
    maze.setEnd(r, c);
    return maze.search(x, y, k);
}
