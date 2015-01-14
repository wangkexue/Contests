#include <cstdio>
#include <climits>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct node {
	int row;
	int col;
	int step;
	node (int r, int c, int s): row(r), col(c), step(s) {}
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

class Solution {
private:
	bool ***dp;
	char ***laser_maze;
	int row;
	int col;
	int tar_row;
	int tar_col;
	int start_row;
	int start_col;
	//static const unordered_set<char> dict;
public:
	Solution(vector<string> &maze, int r, int c): row(r), col(c) {
		int i, j, k, n;
		dp = new bool**[row];
		for (i = 0; i < row; i++) {
			dp[i] = new bool*[col];
			for (j = 0; j < col; j++) {
				dp[i][j] = new bool[4];
				for(k = 0; k < 4; k++)
					dp[i][j][k] = false;
			}
		}
		laser_maze = new char**[row];
		for (i = 0; i < row; i++) {
			laser_maze[i] = new char*[col];
			for (j = 0; j < col; j++) {
				laser_maze[i][j] = new char[4];
				if (maze[i][j] == '>') 
				{
					laser_maze[i][j][0] = '>';
					laser_maze[i][j][1] = 'v';
					laser_maze[i][j][2] = '<';
					laser_maze[i][j][3] = '^';
				}
				else if (maze[i][j] == 'v') {
					laser_maze[i][j][0] = 'v';
					laser_maze[i][j][1] = '<';
					laser_maze[i][j][2] = '^';
					laser_maze[i][j][3] = '>';
				}
				else if (maze[i][j] == '<') {
					laser_maze[i][j][0] = '<';
					laser_maze[i][j][1] = '^';
					laser_maze[i][j][2] = '>';
					laser_maze[i][j][3] = 'v';
				}
				else if (maze[i][j] == '^') {
					laser_maze[i][j][0] = '^';
					laser_maze[i][j][1] = '>';
					laser_maze[i][j][2] = 'v';
					laser_maze[i][j][3] = '<';
				}
				else {
					if (maze[i][j] == 'S') {
						start_row = i;
						start_col = j;
					}
					else if (maze[i][j] == 'G') {
						tar_row = i;
						tar_col = j;
					} 
				    for(k = 0; k < 4; k++)
					    laser_maze[i][j][k] = maze[i][j];
				}
			}
		}
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++)
				for(k = 0; k < 4; k++) {
					switch (laser_maze[i][j][k]) {
						case '>':
							for(n = j+1; n < col && valid(maze[i][n]); n++) {
								dp[i][n][k] = true;
							}
							break;
						case 'v':
							for(n = i+1; n < row && valid(maze[n][j]); n++) {
								dp[n][j][k] = true;
							}
							break;
						case '<':
							for(n = j-1; n >= 0 && valid(maze[i][n]); n--) {
								dp[i][n][k] = true;
							}
							break;
						case '^':
							for(n = i-1; n >= 0 && valid(maze[n][j]); n--) {
								dp[n][j][k] = true;
							}
							break;
						default:
						    break;
					}
				}
	}

	bool valid(char x) {
		return x != '#' && x != '<' && x != '>' && x != '^' && x != 'v';
	}

	// void test_laser() {
	// 	int i, j, k;
	// 	for (k = 0; k < 4; k++) {
	// 		for (i = 0; i < row; i++) {
	// 			for (j = 0; j < col; j++) {
	// 				printf("%c ", laser_maze[i][j][k]);
	// 			}
	// 			printf("\n");
	// 		}
	// 		printf("================\n");
	// 	}
	// }

	~Solution() {
		int i, j;
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) { 
				delete [] dp[i][j];
				delete [] laser_maze[i][j];
			}
			delete [] dp[i];
			delete [] laser_maze[i];
		}
		delete [] dp;
		delete [] laser_maze;
	}

	int solve() {
		queue<node> bfs;
		bfs.push(node(start_row, start_col, 0));
		char laser_maze_cur;
		while (!bfs.empty()) {
			node cur = bfs.front();
			bfs.pop();
			if (cur.row == tar_row && cur.col == tar_col)
				return cur.step;
			cur.step++;
			int i, r, c;
			for (i = 0; i < 4; i++) {
				r = cur.row + dx[i];
				c = cur.col + dy[i];
				if (r >= 0 && r < row && c >= 0 && c < col && !dp[r][c][cur.step % 4] && valid(laser_maze[r][c][cur.step % 4])) {
					bfs.push(node(r, c, cur.step));
					dp[r][c][cur.step % 4] = true;
				}
			}
		}
		return -1;
	}
/*
	int solve() {
		// base case 1 step to goal
		if ((tar_row == start_row + 1 && tar_col == start_col && laser_maze[tar_row][tar_col][0] != 'x') ||
			(tar_row == start_row - 1 && tar_col == start_col && laser_maz[tar_row][tar_col][0] != 'x') ||
			(tar_row == start_row && tar_col + 1 == start_col && laser_maze[tar_row][tar_col][0] != 'x') ||
			(tar_row == start_row && tar_col - 1 == start_col && laser_maze[tar_row][tar_col][0] != 'x')
			)
			return 1;
		dfs(1, start_row + 1, start_col);
		dfs(1, start_row - 1, start_col);
		dfs(1, start_row, start_col + 1);
		dfs(1, start_row, start_col - 1);
		int mini = INT_MAX;
		for (int i = 0; i < 4; i++)
			if (dp[tar_row][tar_col][i] < mini)
				mini = dp[tar_row][tar_col][i];
		return mini;
	}

	void dfs(int step, int pos_row, int pos_col) {
		int phase = step % 4;
		if (pos_row < 0 || pos_row >= row || pos_col < 0 || pos_col >= col ||
			laser_maze[pos_row][pos_col][phase] == 'x' ||
			laser_maze[pos_row][pos_col][phase] == '#' ||
			dict.find(laser_maze[pos_row][pos_col][phase]) != dict.end() || 
			step > dp[pos_row][pos_col][phase] ||
			step > dp[tar_row][tar_col][0] ||
			step > dp[tar_row][tar_col][1] ||
			step > dp[tar_row][tar_col][2] ||
			step > dp[tar_row][tar_col][3])
			return;
		//if (laser_maze[pos_row][pos_col][phase] != 'G' || laser_maze[pos_row][pos_col][(phase + 1) % 4] != 'x')
		dp[pos_row][pos_col][phase] = step;
		dfs(step + 1, pos_row + 1, pos_col);
		dfs(step + 1, pos_row - 1, pos_col);
		dfs(step + 1, pos_row, pos_col + 1);
		dfs(step + 1, pos_row, pos_col - 1);
	}
*/
};

//const unordered_set<char> Solution::dict = unordered_set<char>({'>', 'v', '<', '^'});


int main() {
	int t, i, j;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		int row, col;
		scanf("%d %d", &row, &col);
		//char maze[row][col+1];
		vector<string> maze(row);
		for (j = 0; j < row; j++) {
			//scanf("%s", &maze[j]);
			cin >> maze[j];
		}
		// for (j = 0; j < row; j++) {
		// 	for (int k = 0; k < col; k++)
		// 		printf("%c ", maze[j][k]);
		// 	printf("\n");
		// }
		Solution sol(maze, row, col);
		//sol.test_laser();
		int r = sol.solve();
		if (r == -1)
		    printf("Case #%d: %s\n", i, "impossible");
		else
			printf("Case #%d: %d\n", i, r);
	}
}

