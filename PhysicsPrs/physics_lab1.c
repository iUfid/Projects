#include <stdio.h>
#include <string.h>

double findArMean(char filename[]) {
	FILE* f = fopen(filename, "r");
	int k = 0;
	double x, sum, result;
	while(fscanf(f, "%lf", &x) != EOF) {
		sum += x;
		k += 1;
	}

	fclose(f);
	result = sum / k;
	return result;
}

void getResults(char filename[]) {
	double armean = findArMean(filename);

	FILE* fr = fopen(filename, "r");
	int i = 0;
	char partofstr[100];
	char writefile[100] = "";
	while(filename[i] != '.') {
		partofstr[i] = filename[i];
		i++;
	}
	fclose(fr);
	strcat(writefile, partofstr);
	strcat(writefile, "_result");
	strcat(writefile, ".txt");

	fr = fopen(filename, "r");
	FILE* fw = fopen(writefile, "w");
	double x, res1, res2;
	i = 1;
	while(fscanf(fr, "%lf", &x) != EOF) {
		res1 = x - armean;
		res2 = res1 * res1;
		fprintf(fw, "%d.  %lf     %lf     %lf\n", i, x, res1, res2);
		i++;
	}
	fprintf(fw, "\n%lf - среднее значение T\n", armean);

	fclose(fr);
	fclose(fw);
}




int main() {
	char name1[100];
	scanf("%s", name1);
	getResults(name1);

	return 0;
}









