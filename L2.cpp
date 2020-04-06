#include<mpi.h>
#include<iostream>
#include<string.h>

using namespace std;

int main(int argc, char* argv[]) {
	int massege;
		int rank;
		int size;
		int number[20];
		int TAG = 0;
		MPI_Status status;
		MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		if (rank == 0) {
			cout << "Enter number" << endl;
			cin >> number[20];
			MPI_Send(&number,20 ,MPI_INT, 1, TAG, MPI_COMM_WORLD);
		}
		else {
			MPI_Recv(&number, 20, MPI_INT, 0, TAG, MPI_COMM_WORLD,&status);
			cout << "Your number:" << number << endl;
		
		}
		
		
		
		
		
		MPI_Finalize();
		return 0;
}