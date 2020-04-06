#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <ctime>



using namespace std;
int main(int argc, char**argv) {
	int rank;
	int mass[100];
	int mass2D[5][4];
	int sum=0;
	int sum1 = 0;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		if (rank == 0) {
			for (int i = 0; i < 100; i++) {
				mass[i] = rand()%100;
				cout << mass[i]<<" ";
				if ((i % 3) == 0)
				{
					sum += mass[i];
				}
			}
			cout << "Task1:" << sum<<endl;
			cout << "++++++++++++++++";
		}

		if (rank == 1) {
			int i=0, j=0;
			mass2D[i][j] = rand();
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 4; j++) {
					mass2D[i][j]=rand()%100;
					cout << mass2D[i][j]<<"\t";
					cout << endl;
				}
			}

			for (int i = 0, j = 0; i < 5 && j < 4; ++i, ++j)
			{
				sum1 += mass2D[i][j];
			}

			cout << "Task2:" << sum1;
		}

	MPI_Finalize();
	return 0;
}

