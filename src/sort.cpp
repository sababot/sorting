#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "bubble/bubble.h"
#include "bucket/bucket.h"
#include "comb/comb.h"
#include "counting/counting.h"
//#include "heap/heap.h"
#include "insertion/insertion.h"
#include "merge/merge.h"
#include "quick/quick.h"
#include "radix/radix.h"
#include "selection/selection.h"
#include "shell/shell.h"

using namespace std;

int n = 25;
int sort_array[25] = {4, 4, 6, 2, 1, 7, 8, 3, 9, 12, 15, 12, 9, 4, 5};
int tmp_array[25];
int turn = 1;

bool bubble_bool;
bool merge_bool;
bool quick_bool;
bool counting_bool;
bool insertion_bool;

int quick_turn;

class olcSort : public olc::PixelGameEngine
{
public:
	olcSort()
	{
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Clear screen
		Clear(olc::BLACK);

		// Display array
		for (int i = 0; i < n; i++)
		{
			FillRect((i * 18) + 10, 50, 18, sort_array[i] * 7, olc::WHITE);
		}

		// Generate UI
		FillRect(10, 10, 60, 30, olc::YELLOW);
		FillRect(80, 10, 60, 30, olc::BLUE);
		FillRect(150, 10, 60, 30, olc::BLUE);

		// Click new button
		if (GetMouse(0).bReleased)
		{
			if (((int)GetMouseX() >= 10 && (int)GetMouseX() <= 70) && ((int)GetMouseY() >= 10 && (int)GetMouseY() <= 40))
			{
				for (int i = 0; i < n; i++)
				{
					sort_array[i] = rand() % 25;
				}
				
				bubble_bool = false;
				quick_bool = false;
			}
		}

		// Click bubble button
		if (GetMouse(0).bReleased)
		{
			if (((int)GetMouseX() >= 80 && (int)GetMouseX() <= 120) && ((int)GetMouseY() >= 10 && (int)GetMouseY() <= 40))
			{
				bubble_bool = true;
			}
		}

		// Click quick button
		if (GetMouse(0).bReleased)
		{
			if (((int)GetMouseX() >= 140 && (int)GetMouseX() <= 200) && ((int)GetMouseY() >= 10 && (int)GetMouseY() <= 40))
			{
				quick_bool = true;
				quick_sort_step(sort_array, 0, n);
			}
		}

		// Bubble
		if (bubble_bool)
		{
			memcpy(tmp_array, sort_array, sizeof(tmp_array));
			bubble(tmp_array, n);
			if (tmp_array != sort_array)
			{
				bubble_step(sort_array, n);
				usleep(1);
			}
		}

		// quick
		if (quick_bool)
		{
			memcpy(tmp_array, sort_array, sizeof(tmp_array));
			bubble(tmp_array, n);

			if (tmp_array != sort_array)
			{
				quick_sort_step(sort_array, 0, n);
				//quick_sort_step(sort_array, p_step + 1, n);
				usleep(1);
			}
		}

		return true;
	}
};

int main()
{
	olcSort sort_app;
	
	if (sort_app.Construct(480, 272, 2, 2))
		sort_app.Start();

	return 0;
}
