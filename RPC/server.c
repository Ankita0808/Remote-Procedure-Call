#include "header.h"
#include <time.h>

void doMultiply(float *a, float *b, float *c, int size1, int size2, int size3)
{
	int i, j, k;
	for (i = 0; i < size1; i++)
		for(j = 0; j < size3; j++)
			for (k = 0; k < size2; k++)
				c[i * size3 + j] += a[i * size2 + k] * b[k * size3 + j];
				
}


void doSort(float *a, float *b, int size1)
{
	int modify = 0;
	float temp;
	int i, j;
	
	for (i=0; i<size1; i++)
		b[i] = a[i];
	
	for (i=0; i<size1-1; i++)
		for (j=i; j<size1; j++)
			{
				if (b[i] > b[j])
				{
					temp = b[j];
					b[j] = b[i];
					b[i] = temp;
				}
			}
}


void doMin(float *a, float *b, int size1)
{
	int i;

	*b = 100000;
	for (i = 0; i < size1; i++)
		if(a[i] < *b)
			*b = a[i];
}


void doMax(float *a, float *b, int size1)
{
	int i;

	*b = -1;
	for (i = 0; i < size1; i++)
		if(a[i] > *b)
			*b = a[i];
}

int main()
{	
	int sockfd;
	char server_ip[100], server_port[100];
	char *program_name, *procedure_name;
	int program_version, i,j;
	
	program_name = "matrix";
	program_version = 1;
	
	//create TCP socket
	if ((sockfd = createTCP_server(server_ip, server_port)) == 0)
		{
			return -1;
		}
		
	printf("Server IP and Port is %s %s\n", server_ip, server_port);
	
		
	sendRegister(program_name, program_version, 
						"multiply", server_ip, server_port);
	sendRegister(program_name, program_version, 
						"sort", server_ip, server_port);
	sendRegister(program_name, program_version, 
						 "min", server_ip, server_port);
	sendRegister(program_name, program_version, 
						"max", server_ip, server_port);						
	
	runServer(sockfd);
	return 0;
}
