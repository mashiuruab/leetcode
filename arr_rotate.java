public void rotate(int[][] matrix) {
	int temp;
	int dest_j = 0;

	for(int i=0;i<matrix.length;i++){
		for(int j=0;j<matrix[i].length;j++){
			dest_j = j + matrix[i].length - 1;
			temp = matrix[i][dest_j];
			matrix[i][dest_j] = matrix[i][j];
		}
	}        
}
