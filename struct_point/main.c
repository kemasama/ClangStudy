/***********************************************
　5人の生徒の平均点、最大点、最低点を
　構造体を使い標準出力する。

　Compile
　　GCC 9.4.0
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct subject {
	int	subject_id;
	int	score;
} Subject;

typedef struct student {
	int	student_id;
	Subject	subjects[5];
} Student;

/***********************************************
Function
	配列から最大を取得する
Caution
Return	最大値
***********************************************/
int
get_max(
int	*array,	/* (i) : 配列 */
int	array_size	/* (i) : 配列の大きさ */
)
{
	int	i	;
	int	max_value	= array[0];

	for ( i = 1 ; i < array_size ; i++ ) {
		if (array[i] > max_value) {
			max_value	= array[i];
		}
	}

	return max_value;
}

/***********************************************
Function
	配列から最低を取得する
Caution
Return	最低値
***********************************************/
int
get_min(
int	*array,	/* (i) : 配列 */
int	array_size	/* (i) : 配列 */
)
{
	int	i	;
	int	min_value	= array[0];

	for ( i = 1 ; i < array_size ; i++ ) {
		if (array[i] < min_value) {
			min_value	= array[i];
		}
	}

	return min_value;
}
/***********************************************
Function
	配列から平均を取得する
Caution
Return	平均値
***********************************************/
int
get_average(
int	*array,	/* (i) : 配列 */
int	array_size	/* (i) : 配列のサイズ */
)
{
	int	i	;
	int	average	;
	int	total	= 0;

	for ( i = 0 ; i < array_size ; i++ ) {
		total	+= array[i];
	}

	average	= total / array_size;

	return average;
}

/********************************************
Function
	生徒配列を初期化する
Caution
Return	正常時は0を返す
********************************************/
int
init_students(
Student*	students,	/* (i) : 生徒配列 */
int	student_count	/* (i) : 生徒数 */
)
{
	int	i;
	int	j;

	for ( i = 0 ; i < student_count ; i++ ) {
		students[i].student_id	= i;

		for ( j = 0 ; j < 5; j++ ) {
			students[i].subjects[j].subject_id = j;
			students[i].subjects[j].score = 0;
		}
	}

	return 0;
}

/***********************************************
Function
	生徒の点数をランダム生成する
Caution
Return	正常時は0を返す
***********************************************/
int
rand_score_students(
Student*	students,	/* (i) : 生徒配列 */
int	student_count	/* (i) : 生徒数 */
)
{
	int	i;
	int	j;

	srand((int)time(NULL));

	for ( i = 0 ; i < student_count ; i++ ) {
		//printf("生徒番号：%d\r\n", i);

		for ( j = 0 ; j < 5 ; j++ ) {
			students[i].subjects[j].score	= rand() % 100 + 1;

			//printf("教科番号：%d\t点数：%d\r\n", j, students[i].subjects[j].score);
		}
	}

	return 0;
}

/***********************************************
Function
	生徒配列から特定の教科番号から配列を返す
Caution
Return	正常時は0を返す
***********************************************/
int
get_subject_score_array(
int	*array,
Student*	students,
int	student_count,
int	subject_id
)
{
	int	i;
	int	j;

	for ( i = 0 ; i < student_count ; i++ ) {
		for ( j = 0 ; j < 5 ; j++ ) {
			if (students[i].subjects[j].subject_id != subject_id) {
				continue;
			}

			array[i]	= students[i].subjects[j].score;
		}
	}

	return 0;
}

/***********************************************
Function
	生徒配列から平均点、最大点、最低点を出力する
Caution
Return	正常時は0を返す
***********************************************/
int
print_students(
Student*	students,
int	student_count
)
{
	int	j;

	int	arr[student_count];
	int	val_avg;
	int	val_max;
	int	val_min;
	char	subject_name[6];

	for ( j = 0 ; j < 5 ; j++ ) {
		get_subject_score_array(arr, students, student_count, j);
		val_avg	= get_average(arr, student_count);
		val_max	= get_max(arr, student_count);
		val_min	= get_min(arr, student_count);

		printf("教科番号：%d\r\n", j);
		printf("平均点：%d\t", val_avg);
		printf("最大点：%d\t", val_max);
		printf("最低点：%d\r\n", val_min);

		printf("\r\n");
	}

	return 0;
}

/***********************************************
Function
	メイン関数

	5人の生徒の平均点、最大点、最低点を
	構造体を使い標準出力する。
Caution
Return	正常時は0を返す
***********************************************/
int
main()
{
	int	student_count	= 5;
	Student	students[student_count];

	init_students(students, student_count);
	rand_score_students(students, student_count);

	print_students(students, student_count);

	return 0;
}
