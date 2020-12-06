#include<iostream>
#include<algorithm>

using namespace std;

#define MAXNUM 100000

class Priority_Queue {
private:
	int arr[MAXNUM];
	int current = 1;

public:
	/***************** Creation ******************/
	Priority_Queue() {
		fill(this->arr, this->arr + 100000, 0);
	}

	/***************** Method ********************/
	void push(int x) 
	{
		// current index of input
		arr[this->current] = x;

		// tmporary index to compare
		int cmp_idx = this->current;
		while (cmp_idx != 1)
		{
			// parent node: cmp_idx / 2
			// child node: cmp_idx
			if (abs(arr[cmp_idx / 2]) < abs(arr[cmp_idx]))
			{
				// located right position
				break;
			}
			else if (abs(arr[cmp_idx / 2]) == abs(arr[cmp_idx]))
			{
				if (arr[cmp_idx / 2] > arr[cmp_idx])
				{
					// swap order
					this->swap(&(this->arr[cmp_idx]), &(this->arr[cmp_idx / 2]));
					cmp_idx /= 2;
				}
				else break;
			}
			else
			{
				// swap order
				this->swap(&(this->arr[cmp_idx]), &(this->arr[cmp_idx / 2]));
				cmp_idx /= 2;
			}
		}

		// plus index
		this->current += 1;
	}

	void pop() 
	{
		// current root
		int root = 1;

		// if current == root
		if (this->current == root) return;

		// if current idx > 1
		if(this->current > root) this->current -= 1;
		
		// initialize arr[root]
		this->arr[root] = this->arr[this->current];
		
		// erase arr[this->current] = 0
		this->arr[this->current] = 0;

		// update
		while (true)
		{
			// index of left, right node
			int left_idx = root * 2;
			int right_idx = root * 2 + 1;

			// left, right node
			int *left_node = &(this->arr[left_idx]);
			int *right_node = &(this->arr[right_idx]);
			int *root_node = &(this->arr[root]);

			// child node -> two
			bool two_flag = false;

			// child node -> one
			int one_flag = false;

			// child node -> zero
			int zero_flag = false;

			int cnt = 0;
			if (*left_node != 0) cnt += 1;
			if (*right_node != 0) cnt += 1;

			if (cnt == 0) zero_flag = true;
			else if (cnt == 1) one_flag = true;
			else if (cnt == 2) two_flag = true;

			// process by flag
			if (zero_flag) break;
			else if (one_flag)
			{
				// absolute compare
				if (abs(*root_node) < abs(*left_node)) break;
				if (abs(*root_node) == abs(*left_node))
				{
					if (*root_node <= *left_node) break;
					this->swap(root_node, left_node);
					root = left_idx;
				}
				else
				{
					this->swap(root_node, left_node);
					root = left_idx;
				}
			}
			else if (two_flag)
			{
				// absolute compare
				if (abs(*left_node) < abs(*right_node))
				{
					if (abs(*root_node) < abs(*left_node)) break;
					if (abs(*root_node) == abs(*left_node))
					{
						if (*root_node <= *left_node) break;
						this->swap(root_node, left_node);
						root = left_idx;
					}
					else
					{
						this->swap(root_node, left_node);
						root = left_idx;
					}
				}
				else if (abs(*left_node) > abs(*right_node))
				{
					if (abs(*root_node) < abs(*right_node)) break;
					if (abs(*root_node) == abs(*right_node))
					{
						if (*root_node <= *right_node) break;
						this->swap(root_node, right_node);
						root = right_idx;
					}
					else
					{
						this->swap(root_node, right_node);
						root = right_idx;
					}
				}
				else if (abs(*left_node) == abs(*right_node))
				{
					if (*left_node == *right_node)
					{
						if (abs(*root_node) < abs(*left_node)) break;
						if (abs(*root_node) == abs(*left_node))
						{
							if (*root_node <= *left_node) break;
							this->swap(root_node, left_node);
							root = left_idx;
						}
						else
						{
							this->swap(root_node, left_node);
							root = left_idx;
						}
					}
					else if (*left_node < *right_node)
					{
						if (abs(*root_node) < abs(*left_node)) break;
						if (abs(*root_node) == abs(*left_node))
						{
							if (*root_node <= *left_node) break;
							this->swap(root_node, left_node);
							root = left_idx;
						}
						else
						{
							this->swap(root_node, left_node);
							root = left_idx;
						}
					}
					else if (*left_node > *right_node)
					{
						if (abs(*root_node) < abs(*right_node)) break;
						if (abs(*root_node) == abs(*right_node))
						{
							if (*root_node <= *right_node) break;
							this->swap(root_node, right_node);
							root = right_idx;
						}
						else
						{
							this->swap(root_node, right_node);
							root = right_idx;
						}
					}
				}
			}
		}
	}

	int top()
	{
		if (this->current == 1) return 0;
		else return arr[1];
	}

	void swap(int *a, int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Priority_Queue pq;

	int n;
	int tmp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;

		if (tmp == 0)
		{
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
		{
			pq.push(tmp);
		}
	}

	

	return 0;
}