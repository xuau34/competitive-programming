<?php
$f1 = STDIN;
list($N, $L, $R) = explode(" ", fgets(STDIN));
$N = (int) $N;
$L = (int) $L;
$R = (int) $R;
//fscanf( $f1, "%d %d %d", &$N, &$L, &$R);
$arr[0] = explode(" ", fgets(STDIN));
$arr[1] = explode(" ", fgets(STDIN));
/*
for( $i = 1; $i <= $N; $i++){
  fscanf( $f1, "%d", &$j);
  $arr[0][$i] = $j;
}
for( $i = 1; $i <= $N; $i++){
  fscanf( $f1, "%d", &$j);
  $arr[1][$i] = $j;
}
*/
$L -= 1;
$R -= 1;
for( $i = 0; $i < $N; $i++){
  if( $i >= $L && $i <= $R){
    $box1[ (int)$arr[0][$i] ]++;
    $box2[ (int)$arr[1][$i] ]++;
  }else if( $arr[0][$i] != $arr[1][$i] ){
    printf("LIE\n");
    return;
  }
}
if( count( $box1 ) != count( $box2 ) ){
  printf("LIE\n");
  return;
}

foreach( $box1 as $i => $v){
  //printf("(%d, %d) vs (%d, %d)\n", $i, $v, $i, $box1[$i]);
  if( $v != $box2[$i] ){
    printf("LIE\n");
    return;
  }
}
printf("TRUTH\n");

?>
