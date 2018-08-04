//Indexing Procs
	proc SetGridItemColorCAString( string $isSelectedZz, int $Color ){
	if ( `objExists $isSelectedZz` == 1  ) {
	int $ModNi =  (fmod($Color, 30))+1 ;
	string $isSelectedZx[];
	$isSelectedZx = `listRelatives $isSelectedZz`;
	string $SetCol = `setAttr ($isSelectedZx[0]+".overrideColor ") $ModNi `;
	}
	}


	proc int [] Index_NxNxN_GetGrid(int $place, int $grid){
	float $findXY = float($place)/ float ($grid) ;
	float $val  =  (int)($findXY);
	float $findXYb = (($val*$grid)/$grid);
	float $findXYa = ((-1*$findXYb*$grid)+$place)+$grid;
	float $IndexA = fmod($findXYa,$grid);
	float $IndexB = fmod($findXYb,$grid);
	int $XY[];
	$XY = {int ($IndexA), int ($IndexB)};
	return $XY;
	}


	proc int Grid_NxNxN_GetIndex(int $i, int $j , int $grid){
	//
	int $gridX = $grid;
	int $gridY = $grid;
	int $Xi = fmod($i,$gridX);
	int $Yi = fmod($j,$gridY)+1;
	int $row = $Yi * $gridY;
	int $rowB = $Yi * ($gridY-1);
	int $place =((($row+$Xi)-$gridY));
	return $place;
	}


	proc int life_check2d(int $x, int $y, int $gridPtsN, int $OnorOff[],int $StatesCount[],int $cycle){
	/*
	int $TTT[]= Index_NxNxN_GetGrid(2311 ,  $gridX);
	int $gridPtsN=$gridX;
	//9, 7,$gridX,  $OnorOff
	int $x=$TTT[0]; int $y=$TTT[1];

	int $bOldVal= $addOnstate[$Point];
	*/
	global string $CreatedItemG[];
	global int $iClo;
	global int $SCount[];

	int $Point = Grid_NxNxN_GetIndex($x,$y,$gridPtsN);
	string $TempPoints[]; 


	int $R =0;
	int $bOldVal= $StatesCount[$Point];
	$R = $bOldVal;
	int $total=0;
	int $modCnt = 0;
							if ($bOldVal > 1) // decay
					{
						if ($bOldVal < $iClo - 1){
							$R = $bOldVal + 1;
	$SCount[$Point]+=1;
						}else{
							$R = 0;
	$SCount[$Point]=0;
	}
					} else // 0, 1
					{

		int $total;
		int $GridXi = $gridPtsN; 
		int $GridYi = $gridPtsN; 
		int $GridZi = $gridPtsN;
		$plusx = (($x+1) % $GridXi);
		 if($x >= 0)
		$minusx = (($x-1)% $GridXi)+$GridXi;
		 else
		 $minusx = ($GridXi);
		$plusy = (($y+1) % $GridYi);
		 if($y >= 0)
		$minusy = (($y-1)% $GridYi)+$GridYi;
		 else
		 $minusy = ($GridYi);
		int $allIndexCA[];
	$allIndexCA[0] = Grid_NxNxN_GetIndex( $minusx,$y,$gridPtsN);
	$allIndexCA[1] = Grid_NxNxN_GetIndex( $plusx,$y,$gridPtsN);
	$allIndexCA[2] = Grid_NxNxN_GetIndex( $x,$plusy,$gridPtsN);
	$allIndexCA[3] = Grid_NxNxN_GetIndex( $x,$minusy,$gridPtsN);
	$allIndexCA[4] = Grid_NxNxN_GetIndex( $minusx,$minusy,$gridPtsN);
	$allIndexCA[5] = Grid_NxNxN_GetIndex( $plusx,$minusy,$gridPtsN);
	$allIndexCA[6] = Grid_NxNxN_GetIndex( $minusx,$plusy,$gridPtsN);
	$allIndexCA[7] = Grid_NxNxN_GetIndex( $plusx,$plusy,$gridPtsN);
	//$allIndexCA[8] = Grid_NxNxN_GetIndex($x,$y,$gridPtsN);

	//$total=0;
	for($eachLocCA in $allIndexCA){
	//print ($addOnstate[$eachLocCA]+"\n");
	//if($addOnstate[$eachLocCA]==1){
	 if($StatesCount[$eachLocCA]==1){
	$total++;
	}
	}
	//print $total;

	//for($eachLocCA in $allIndexCA){
	// $total += $OnorOff[$eachLocCA];
	//}
	///////////////////// print $total ;

				if ($bOldVal != 0) {
						// print ("A"+"\n");
							if(SetRulesS($total)==1){
							//print ("Ab"+"\n");
	$SCount[$Point]=1;
								$R=1;
							}else{ if($bOldVal < $iClo - 1){
						  //print ("B"+"\n");
								$R= $bOldVal + 1;
	$SCount[$Point]+=1;
							}else{
		$SCount[$Point]=0;						$R=0;
		 // print ("Ba"+"\n");	
	}
	}
						}else{
			// print ("C"+"\n");

							if (SetRulesB($total)==1){
	$SCount[$Point]=1;	
								$R=1;}

							 //print ("Ca"+"\n");
						}

			 // print $R;

	///////////////////

					}



	if($R>0){
	$R=1;}else{$R=0;}

	// print $R;

	return $R;
	}

	/*

		if ($bOldVal == 1){
	if (SetRulesS($total)==1){
	$R= $bOldVal;
	if (SetRulesB($total)==1){
	$R=1;
	}
	}else{ $R=0; }

	}

		if ($bOldVal == 0){
	if (SetRulesS($total)==1){
	if (SetRulesB($total)==1){
	$R=1;
	}
	}
	if (SetRulesB($total)==1){
	$R=1;
	}
	}

	//print $R;
	///////////////////
	//OLD
	// but good

	proc int life_check2d(int $x, int $y, int $gridPtsN, int $OnorOff[],int  $StatesCount,int $cycle){

	global string $CreatedItemG[];
	int $Point = Grid_NxNxN_GetIndex($x,$y,$gridPtsN);
	string $TempPoints[]; 
	int $total=0;
	int $modCnt = 0;
		int $total;
		int $GridXi = $gridPtsN; 
		int $GridYi = $gridPtsN; 
		int $GridZi = $gridPtsN;
		$plusx = (($x+1) % $GridXi);
		 if($x >= 0)
		$minusx = (($x-1)% $GridXi)+$GridXi;
		 else
		 $minusx = ($GridXi);
		$plusy = (($y+1) % $GridYi);
		 if($y >= 0)
		$minusy = (($y-1)% $GridYi)+$GridYi;
		 else
		 $minusy = ($GridYi);
		int $allIndexCA[];
	$allIndexCA[0] = Grid_NxNxN_GetIndex( $minusx,$y,$gridPtsN);
	$allIndexCA[1] = Grid_NxNxN_GetIndex( $plusx,$y,$gridPtsN);
	$allIndexCA[2] = Grid_NxNxN_GetIndex( $x,$plusy,$gridPtsN);
	$allIndexCA[3] = Grid_NxNxN_GetIndex( $x,$minusy,$gridPtsN);
	$allIndexCA[4] = Grid_NxNxN_GetIndex( $minusx,$minusy,$gridPtsN);
	$allIndexCA[5] = Grid_NxNxN_GetIndex( $plusx,$minusy,$gridPtsN);
	$allIndexCA[6] = Grid_NxNxN_GetIndex( $minusx,$plusy,$gridPtsN);
	$allIndexCA[7] = Grid_NxNxN_GetIndex( $plusx,$plusy,$gridPtsN);
	//$allIndexCA[8] = Grid_NxNxN_GetIndex($x,$y,$gridPtsN);

	int $R =0;
	int $bOldVal= $OnorOff[$Point];

			for($eachLocCA in $allIndexCA){
			$total += $OnorOff[$eachLocCA];
			}
		if ($bOldVal == 1){
	if (SetRulesS($total)==1){
	$R= $bOldVal;
	if (6 <  $StatesCount ){
	if(!($cycle+1==$StatesCount)){
	//$R=0;
	}
	}
	if (SetRulesB($total)==1){
	$R=1;
	}
	}else{ $R=0; }

	}

		if ($bOldVal == 0){
	if (SetRulesS($total)==1){
	if (SetRulesB($total)==1){
	$R=1;
	}
	}
	if (SetRulesB($total)==1){
	$R=1;
	}
	}

	//print $R;

	return $R;
	}

	*/




	proc int SetRulesB(int $total){
	global int $Births[];
	int $TrueFalse=0;
	for($eachN in $Births){
	if($eachN==$total){
	$TrueFalse=1; break;
	}else{$TrueFalse=0;}
	}
	return $TrueFalse;
	}


	proc int SetRulesS(int $total){
	global int $Survivals[];
	int $TrueFalse=0;
	for($eachN in $Survivals){
	if($eachN==$total){
	$TrueFalse=1; break;
	}else{$TrueFalse=0;}
	}
	return $TrueFalse;
	}


	proc PAUSE(){
		playButtonStepForward;
	}


	proc string Loc(float $Points[]){
	//string $LocObjects[] = `polyPlane -w 1 -h 1 -sx 1 -sy 1 -ax 0 1 0 -cuv 2 -ch 0`;
	 string $LocObjects[] = `polyCube -w 1 -h 1 -d 1 -sx 1 -sy 1 -sz 1 -ax 0 1 0 -cuv 4 -ch 0`;
		setAttr ($LocObjects[0]+".translate")  $Points[0] $Points[1] $Points[2];
		return $LocObjects[0];
	}



	global int $Births[];
	global int $Survivals[];
	global int $iClo;


		int $i = 0;
		int $j = 0;
		int $k = 0;

	int $gridX = 37; 
	int $gridY =37; 
	int $gridZ = 37;
	//NOT IN USE
	int $gridThreePtsN[] = {$gridX, $gridY, $gridZ};
	string $PosMasterIndex[];
	int  $OnorOff[];
	int $rndcut = 60;
	int $rnd;
	string $CreatedItem[];
	clear $CreatedItem;
	string $NewLoc[];
	int $x;
	int $y;
	int $z;
	while($x < $gridX){
	$PosMasterIndex[$x]="";
	$x++;	}

		 $x = 0;
		 $y = 0;
		 $z = 0;
	int $countN = 0;
		while($x < $gridX){
			$y =0;
			while($y < $gridY){		 
			$addItString = $PosMasterIndex[$x];
			 $name =  $x + "_" + $z + "_" + $y + ",";
	$addItString += $name;
	$PosMasterIndex[$x] = $addItString;
	vector $TESTVec = << $x, $z, $y >>;
	//Cube $TESTVec;	
	Loc $TESTVec;
	$NewLoc  = `ls -sl`;
	$CreatedItem[`size($CreatedItem)`]=$NewLoc[0];		
				$rnd = rand(70,100);
				if($rnd > $rndcut){
	setAttr ( $NewLoc[0]+".scale") 0.5 0.5 0.5;
	 $OnorOff[`size($OnorOff)`] = 1;
	}else{
	setAttr ( $NewLoc[0]+".scale") 0.1 0.1 0.1;
	 $OnorOff[`size($OnorOff)`] = 0;
	}
			$countN++;
			$y++;
			}
		$x++;
		}

	global string $CreatedItemG[];
	$CreatedItemG=$CreatedItem;
	//RUN ONCE//
	string $allItemsINGRID[] =$CreatedItem;
	size($allItemsINGRID);
	for($eachItemGRID in $allItemsINGRID){
	string $isSelectedZx[];
	$isSelectedZx = `listRelatives $eachItemGRID`;
	setAttr ($isSelectedZx[0]+".overrideEnabled ") 1;
	}



	/////////////////////
	//RESET  $OnorOff = $addOnstateOLD;
	/*
	string $SelItems[]=`ls -sl`;
	//select -r $SelItems;
	string $stringLIST = stringArrayToString($SelItems, ",");
	//$stringLIST = substituteAllString($stringLIST, "pPlane", "");
	// OR $stringLIST = substituteAllString($stringLIST, "locator", "");
	$stringLIST = substituteAllString($stringLIST, "pCube", "");
	int $ListIndex[];
	eval(" $ListIndex ={"+$stringLIST+"} ;");

	*/

	string $SelItems[]=`ls -sl`;
	for($eachLoCi in $SelItems){
	setAttr ( $eachLoCi+".scale") 1 1 1;
	}

	string $SelItems[]=`ls -sl`;
	for($eachLoCi in $SelItems){
	setAttr ( $eachLoCi+".scale") 0.025 0.025 0.025;
	}		

	$ListIndex =sort($ListIndex);
	clear $OnorOff;
	int $iv=$COuntTT=0;
	for($eachLoC in $allItemsINGRID){
	SetGridItemColorCAString($eachLoC, 0);
	 setAttr ($eachLoC+".visibility") 1;
	if(($ListIndex[$iv]-1) == $COuntTT){
	setAttr ( $eachLoC+".scale") 0.5 0.5 0.5;	
	 $OnorOff[`size($OnorOff)`] = 1;
	$iv++;
	}else{
	setAttr ( $eachLoC+".scale") 0.1 0.1 0.1;
	 $OnorOff[`size($OnorOff)`] = 0;
	}
	$COuntTT++;
	}
	int $addOnstate[];
	clear $addOnstate;
	int $addOnstateOLD[];
	 $addOnstateOLD = $OnorOff;

	int $addOnstate[];
	 $addOnstate = $OnorOff;

	$OnorOff=$addOnstateOLD;
	$addOnstate =$addOnstateOLD;



	////////////////////
	float $OffS =0.01;
	float $OnS =1.0;
	int $iii = 0;
	string $tempOnCells[];
	//string $object="pPlane"; //string $object="pCube"; //string $object="locator";
	string $object="pCube";
	int $NEWOnorOff[];
	int $DemoOnOff =0;
	int $countN = 0;
	int $IindexCAT,$IindexCA,$newIntOn[],$newIntOnorOff[];
	string $LocCorrent,$LocTemp;
	clear $NEWOnorOff;
	clear $newIntOnorOff;
	float $Ymove=-1;
	int $ONOFFtemp=0;
	$newIntOnorOff = $OnorOff;

	// WALLED CITY
	int $SurvT[] = {2,3,4,5};
	int $BirthsT[] = {4,5,6,7,8};
	 $Survivals = {0,2,3,4,5,6,7};
	 $Births = {0,1,5,7,8};
	//Replicator
	 $Survivals ={1,3,5,7};
	 $Births = {1,3,5,7};
	//WOW!!
	//234678/124678
	//RobotScales2
	//234678/1234678
	 $Survivals ={2,3,4,6,7,8};
	 $Births = {1,2,3,4,6,7,8};
	//Electric
	//234567/1347
	 $Survivals ={2,3,4,5,6,7};
	 $Births = {1,3,4,7};
	//Life
	 $Survivals ={2,3};
	 $Births = {3};

	//Coagulations
	 $Survivals ={2,3,5,6,7,8};
	 $Births = {3,7,8};


	 switch(fmod(3,3)) {
		case 0:
	 $Survivals ={2,3,4,6,7,8};
	 $Births = {1,2,3,4,6,7,8};
	break;
		case 1:
	 $Survivals ={2,3};
	 $Births = {3};
	break;

		case 2:
	 $Survivals ={2,3,4,5,6,7};
	 $Births = {1,3,4,7};
	break;

	}

	//int $iClo;
	//356/23/6

	//Flaming Starbows
	//   347/23/8
	 $Survivals ={3,4,7};
	 $Births = {2,3};
	$iClo=9;

	 $Survivals ={3,5,6};
	 $Births = {2,3};
	$iClo=6;

	//EXPLODE
	//145678/23/8

	 $Survivals ={1,4,5,6,7,8};
	 $Births = {2,3};
	$iClo=8;

	//Ebb&flow
	012468/37/18

	 $Survivals ={0,1,2,4,6,8};
	 $Births = {3,7};
	$iClo=18;
	//STARWARS
	//345/2/4

	 $Survivals ={3,4,5};
	 $Births = {2};
	$iClo=4;

	 $Survivals ={0,3,4,5};
	 $Births = {2,6};
	$iClo=7;

	$OnorOff=$addOnstateOLD;
	 $addOnstate =$addOnstateOLD;

		int $i = 0;
		int $j = 0;
	int $addOnstateT[]= $addOnstate;
	global int $SCount[];
	$SCount=$addOnstateT;
	vector $ListONVEC[];
	string $ADs[];
	clear $ListONVEC;
	$DemoOnOff =0;
	 $iii = 0;
	int $CountOn=0;
	int $PCountOn=0;
	int $PCtOn=0;
	while($iii <65){

	//clear $ListONVEC;
	clear $tempOnCells;
	clear $newIntOn;
		 $i = 0;
		 $j = 0;
	$countN = 0;
	int $Ns =fmod($iii,4);



		while($i <= $gridX-1){
			$j =0;
			while($j <= $gridY-1){
		
	  $IindexCA = Grid_NxNxN_GetIndex($i, $j , $gridX);
						$IindexCAT= $IindexCA+1;
						$LocTemp = ($object+ $IindexCAT);
						$LocCorrent = ($object+ $IindexCAT);




	$newIntOnorOff[$IindexCA] = life_check2d($i, $j,$gridX,  $OnorOff,$addOnstate,$iii);
			if(($newIntOnorOff[$IindexCA]==1)){
	$CountOn++;
							$ListONVEC[`size($ListONVEC)`]= << $i, $iii, $j >>;
							
								//$addOnstateT[$IindexCA]+=1; 
								$tempOnCells[`size($tempOnCells)`]=$CreatedItem[$IindexCA];
							setAttr ( $LocCorrent+".scale") $OnS $OnS $OnS;	
							SetGridItemColorCAString($LocCorrent, $addOnstate[$IindexCA]+$iClo );

	//setAttr ( $LocCorrent+".translateY") $addOnstate[$IindexCA];	

	 }else{
						
							//$addOnstateT[$IindexCA] = 0; 
							SetGridItemColorCAString($LocCorrent, -1 );
							setAttr ( $LocCorrent+".scale") $OffS $OffS $OffS;
	//setAttr ( $LocCorrent+".translateY") $addOnstate[$IindexCA];	



	}
			$countN++;	
			$j++;
			}
		$i++;
		}

	if($CountOn==$PCountOn){
	$PCtOn++;
	if($PCtOn==5){
	break;
	}
	}else{$PCtOn=0;}
	print ($CountOn+"\n");
	if($CountOn==0){
	print ($CountOn+"\n");
	//break;
	}
	$PCountOn=$CountOn;	
	$CountOn=0;
	 $addOnstate=$SCount;
	// $addOnstate = $addOnstateT;
	$OnorOff = $newIntOnorOff;
	//clear $tempOnCells;
	//clear $ListONVEC;

	$iii++;
	currentTime $iii ;


	}

	/////////////END




	/*
	size($ListONVEC);
	Stree3D($ListONVEC,20);
	*/



		int $i = 0;
		int $j = 0;
	$countN = 0;
		while($i <= $gridX-1){
			$j =0;
			while($j <= $gridY-1){		
	  $IindexCA = Grid_NxNxN_GetIndex($i, $j , $gridX);
	life_Make3d($i, $j,$gridX,  $OnorOff,$addOnstate[$IindexCA],$iii);
	$j++;
	}
	$i++;
	}


	/*
	 switch($Ns) {
		case 0:
	//print ("RobotS"+"\n");
	 $Survivals ={2,3,4,6,7,8};
	 $Births = {1,2,3,4,6,7,8};
	break;

		case 1:
	//print ("Electric"+"\n");
	 $Survivals ={2,3,4,5,6,7};
	 $Births = {1,3,4,7};
	break;

		case 2:
	//print ("Coagulations"+"\n");
	 $Survivals ={2,3,5,6,7,8};
	 $Births = {3,7,8};
	break;

		case 3:
	//print ("LIFE"+"\n");
	 $Survivals ={2,3};
	 $Births = {3};
	break;

	}
	*/



	 $iii = 0;
		int $i = 0;
		int $j = 0;
	while($iii <9){
	 $i = 0;
	 $j = 0;
	$countN = 0;
		while($i <= $gridX-1){
			$j =0;
			while($j <= $gridY-1){		
	  $IindexCA = Grid_NxNxN_GetIndex($i, $j , $gridX);
	$newIntOnorOff[$IindexCA] = life_check2d($i, $j,$gridX,  $OnorOff,$addOnstate[$IindexCA],$iii);
	if(($newIntOnorOff[$IindexCA]==1)){
	$addOnstate[$IindexCA] = $addOnstate[$IindexCA]+1; 
	}else{$addOnstate[$IindexCA] = 0; 
	}
	$countN++;	
			$j++;
			}
		$i++;
		}
	$OnorOff = $newIntOnorOff;
	$iii++;
	}



	global vector $SQUARE_PLANE[];

	$SQUARE_PLANE[0]=<<-0.5, -0.5, 0.5>>;
	$SQUARE_PLANE[1]=<<0.5, -0.5, 0.5>>;
	$SQUARE_PLANE[2]=<<-0.5, 0.5, 0.5>>;
	$SQUARE_PLANE[3]=<<0.5, 0.5, 0.5>>;
	$SQUARE_PLANE[4]=<<-0.5, 0.5, -0.5>>;
	$SQUARE_PLANE[5]=<<0.5, 0.5, -0.5>>;
	$SQUARE_PLANE[6]=<<-0.5, -0.5, -0.5>>;
	$SQUARE_PLANE[7]=<<0.5, -0.5, -0.5>>;

	float $fv =0.5;
	vector $SQUARE_PLANE[];

	$SQUARE_PLANE[0]=<<-$fv, -$fv, $fv>>;
	$SQUARE_PLANE[1]=<<$fv, -$fv, $fv>>;
	$SQUARE_PLANE[2]=<<-$fv, $fv, $fv>>;
	$SQUARE_PLANE[3]=<<$fv, $fv, $fv>>;
	$SQUARE_PLANE[4]=<<-$fv, $fv, -$fv>>;
	$SQUARE_PLANE[5]=<<$fv, $fv, -$fv>>;
	$SQUARE_PLANE[6]=<<-$fv, -$fv, -$fv>>;
	$SQUARE_PLANE[7]=<<$fv, -$fv, -$fv>>;

	proc int [] Index_NxNxN_GetGrid(int $place, int $grid){
	float $findXY = float($place)/ float ($grid) ;
	float $val  =  (int)($findXY);
	float $findXYb = (($val*$grid)/$grid);
	float $findXYa = ((-1*$findXYb*$grid)+$place)+$grid;
	float $IndexA = fmod($findXYa,$grid);
	float $IndexB = fmod($findXYb,$grid);
	int $XY[];
	$XY = {int ($IndexA), int ($IndexB)};
	return $XY;
	}

	proc string makePolygonQUAD( vector $VecPts[])
	{
		int $n = `size($VecPts)`;
		// create the n-sided polygon. 
		//
		string $facet[] ;
		string $cmd = "polyCreateFacet -ch 0  ";
		string $vertStr ;
		float $z = 0.0 ;
		int $i ;
		for( $i = 0 ; $i < $n ; $i++ ) {
			$vertStr += " -p " ;
			$vertStr += $VecPts[$i] ;
		}    

		$cmd += $vertStr ; 
		$cmd += " "; 
		string $facet[] = eval($cmd) ;
		return $facet[0] ;


	}   
	/*


	float $fv =0.5;
	vector $SQUARE_PLANE[];


	$SQUARE_PLANE[0]=<<-$fv, -$fv, $fv>>;
	$SQUARE_PLANE[1]=<<$fv, -$fv, $fv>>;
	$SQUARE_PLANE[2]=<<-$fv, $fv, $fv>>;
	$SQUARE_PLANE[3]=<<$fv, $fv, $fv>>;
	$SQUARE_PLANE[4]=<<-$fv, $fv, -$fv>>;
	$SQUARE_PLANE[5]=<<$fv, $fv, -$fv>>;
	$SQUARE_PLANE[6]=<<-$fv, -$fv, -$fv>>;
	$SQUARE_PLANE[7]=<<$fv, -$fv, -$fv>>;

	vector $S_P[]=$SQUARE_PLANE;


	makePolygonQUAD({$S_P[4],$S_P[5],$S_P[7],$S_P[6]});//z- W
	makePolygonQUAD({$S_P[0],$S_P[1],$S_P[3],$S_P[2]});//z+ E
	makePolygonQUAD({$S_P[5],$S_P[3],$S_P[1],$S_P[7]});//x+ N
	makePolygonQUAD({$S_P[2],$S_P[4],$S_P[6],$S_P[0]});//x- S

	makePolygonQUAD({$S_P[5],$S_P[4],$S_P[2],$S_P[3]});//Y+ U
	makePolygonQUAD({$S_P[1],$S_P[0],$S_P[6],$S_P[7]});//Y- D



	proc string Loc(float $Points[]){
		string $LocObjects[] = `spaceLocator -p 0 0 0`;
		setAttr ($LocObjects[0]+".translate")  $Points[0] $Points[1] $Points[2];
		setAttr ($LocObjects[0]+".scale")  0.15 0.15 0.15;
		return $LocObjects[0];
	}


	int $TTT[]= Index_NxNxN_GetGrid(866 ,  $gridX);
	int $gridPtsN=$gridX;
	//9, 7,$gridX,  $OnorOff
	int $x=$TTT[0]; int $y=$TTT[1];
	*/




	//////////////////////////////////////////////////////////////////////

	proc  life_Make3d(int $x, int $y, int $gridPtsN, int $OnorOff[],int  $StatesCount,int $cycle){




	global vector $SQUARE_PLANE[];
	global string $CreatedItemG[];
	int $Point = Grid_NxNxN_GetIndex($x,$y,$gridPtsN);
	vector $CellV = << $y, 0, $x >>;

	if($OnorOff[$Point]==1){
	string $TempPoints[]; 
	int $total=0;
	int $modCnt = 0;
		int $total,$minusx,$minusy,$plusy,$plusx ;
		int $GridXi = $gridPtsN; 
		int $GridYi = $gridPtsN; 
		int $GridZi = $gridPtsN;
		$plusx = ($x+1);
	 if($plusx > $GridXi-1){
	$plusx=-1;}
		 if($x >= 1){
		$minusx =  ($x-1);
		 }else{
		 $minusx = -1;
	}

		$plusy = ($y+1);
	 if($plusy > $GridXi-1){
	$plusy=-1;}
		 if($y >= 1){
		$minusy = ($y-1);
		 }else{
		 $minusy = -1;
		}

	//select -r $CreatedItemG[0] $CreatedItemG[2] $CreatedItemG[30];

	int $allCorner[];
	int $O_Fc[];

	if(($plusx!=-1)&&($plusy!=-1)){
	$allCorner[0] = Grid_NxNxN_GetIndex($plusx,$plusy,$gridPtsN);
	$O_Fc[0] = $OnorOff[$allCorner[0]];
	}else{$allCorner[0] =-1; $O_Fc[0] =0;}

	if(($minusx!=-1)&&($plusy!=-1)){
	$allCorner[1] = Grid_NxNxN_GetIndex( $minusx,$plusy,$gridPtsN);
	$O_Fc[1] = $OnorOff[$allCorner[1]];
	}else{$allCorner[1] =-1; $O_Fc[1] =0;}

	if(($minusx!=-1)&&($minusy!=-1)){
	$allCorner[2] = Grid_NxNxN_GetIndex($minusx,$minusy,$gridPtsN);
	$O_Fc[2] = $OnorOff[$allCorner[2]];
	}else{$allCorner[2] =-1; $O_Fc[2] =0;}

	if(($plusx!=-1)&&($minusy!=-1)){
	$allCorner[3] = Grid_NxNxN_GetIndex($plusx,$minusy,$gridPtsN);
	$O_Fc[3] = $OnorOff[$allCorner[3]];
	}else{$allCorner[3] =-1; $O_Fc[3] =0;}

	//select -r $CreatedItemG[$Point] $CreatedItemG[$allCorner[1]] ;
	// select -r $CreatedItemG[$Point] $CreatedItemG[$PointX] ;

	int $allIndexCA[];
	int $O_F[];
	if($plusx!=-1){
	$allIndexCA[0] = Grid_NxNxN_GetIndex( $plusx,$y,$gridPtsN);
	$O_F[0] = $OnorOff[$allIndexCA[0]];
	}else{$allIndexCA[0] =-1; $O_F[0] =0;}
	if($plusy!=-1){
	$allIndexCA[1] = Grid_NxNxN_GetIndex( $x,$plusy,$gridPtsN);
	$O_F[1] = $OnorOff[$allIndexCA[1]];
	}else{$allIndexCA[1] =-1; $O_F[1] =0;}
	if($minusx!=-1){
	$allIndexCA[2] = Grid_NxNxN_GetIndex( $minusx,$y,$gridPtsN);
	$O_F[2] = $OnorOff[$allIndexCA[2]];
	}else{$allIndexCA[2] =-1; $O_F[2] =0;}
	if($minusy!=-1){
	$allIndexCA[3] = Grid_NxNxN_GetIndex( $x,$minusy,$gridPtsN);
	$O_F[3] = $OnorOff[$allIndexCA[3]];
	}else{$allIndexCA[3] =-1; $O_F[3] =0;}
	int $NSEW[];
	int $CN=0;
	for($eachLocCA in $allIndexCA){
	if($eachLocCA!=-1){
	if( $OnorOff[$eachLocCA]==0){
	$NSEW[`size($NSEW)`]=$CN;
	}
	}else{
	$NSEW[`size($NSEW)`]=$CN;
	}
	$CN++;
	}
	int $FcornerS[];
	int $cZ[];
	$cZ={3,0,1,2};
	int $CN=0;
	for($eachLocCA in $O_Fc){
	if($eachLocCA==1){
	int $Xcf=$CN;
	int $Ab = $O_F[int(fmod($CN,4))];
	int $Ac = $O_F[int(fmod($CN+1,4))];
	if($Ab+$Ac==0){
	$FcornerS[`size($FcornerS)`]=$cZ[$CN];
	}
	}
	$CN++;
	}
	//print $FcornerS;
	if(`size($FcornerS)`>0){
	CellPolys($FcornerS, $CellV);
	}else{
	vector $ABveci[];
	$ABveci[0]=<<0.5, 0, -0.5>>+$CellV;
	$ABveci[1]=<<-0.5, 0, -0.5>>+$CellV;
	$ABveci[2]=<<-0.5, 0, 0.5>>+$CellV;
	$ABveci[3]=<<0.5, 0, 0.5>>+$CellV;
	makePolygonQUAD({$ABveci[0],$ABveci[1],$ABveci[2],$ABveci[3]});
	}
	/*
	vector $S_P[]=$SQUARE_PLANE;
	int $CN=0;
	for($Vec in $SQUARE_PLANE){
	 $S_P[$CN]=$Vec+$CellV;
	$CN++;
	}
	// CellPolys(int $NumSq[], vector $VecP)
	int $Size =`size($NSEW)`;
	if($Size>0){
	for($Ii=0;  $Ii<$Size; $Ii++){
	 switch($NSEW[$Ii]) {
		case 0:
	makePolygonQUAD({$S_P[4],$S_P[5],$S_P[7],$S_P[6]});//z- W
	break;
		case 1:
	makePolygonQUAD({$S_P[0],$S_P[1],$S_P[3],$S_P[2]});//z+ E
	break;
		case 2:
	makePolygonQUAD({$S_P[5],$S_P[3],$S_P[1],$S_P[7]});//x+ N
	break;
		case 3:
	makePolygonQUAD({$S_P[2],$S_P[4],$S_P[6],$S_P[0]});//x- S
	break;
	}
	}
	}
	*/
	}

	}




	string $ObjectListX[] =`ls -sl -fl`;
	vector $ABvec[] =  PointArrayT($ObjectListX);
	print $ABvec;

	{"pPlane1.vtx[3]","pPlane1.vtx[2]", "pPlane1.vtx[0]","pPlane1.vtx[1]"} ;

	vector $ABvec[] =  PointArrayT({"pPlane1.vtx[3]","pPlane1.vtx[2]", "pPlane1.vtx[0]","pPlane1.vtx[1]"} );
	print $ABvec;

	Loc $ABvec[0];



	vector $DirecS[];
	$DirecS[0]=<<1,0,0>>;
	$DirecS[1]=<<-1,0,0>>;
	$DirecS[2]=<<0,0,1>>;
	$DirecS[3]=<<0,0,-1>>;

	////////////////



	proc CellPolys(int $NumSq[], vector $VecP){

	//delete  $AllPolys;
	//clear $AllPolys;

	string $AllPolys[];

	vector $ABvec[];
	$ABvec[0]=<<0.5, 0, -0.5>>+$VecP;
	$ABvec[1]=<<-0.5, 0, -0.5>>+$VecP;
	$ABvec[2]=<<-0.5, 0, 0.5>>+$VecP;
	$ABvec[3]=<<0.5, 0, 0.5>>+$VecP;
	vector $DirecSs[];
	$DirecSs[0]=<<1,0,0>>;
	$DirecSs[1]=<<0,0,1>>;
	vector $DirecS[];
	$DirecS[0]=<<0,0,1>>;
	$DirecS[1]=<<1,0,0>>;
	$DirecS[2]=<<0,0,-1>>;
	$DirecS[3]=<<-1,0,0>>;
	/////////////////////
	int $Ndir2Sq[];
	$Ndir2Sq[2]=0;
	$Ndir2Sq[3]=-1;
	$Ndir2Sq[4]=3;
	$Ndir2Sq[6]=1;
	$Ndir2Sq[8]=-1;
	$Ndir2Sq[12]=2;
	///////////////////////
	int $Ndir3Sq[];
	$Ndir3Sq[7]= 3;
	$Ndir3Sq[6]= 0;
	$Ndir3Sq[9]=1;
	$Ndir3Sq[8]=3;
	////////////////////
	float $Fe =1.0/3.0;
	vector $EdgeV[];
	vector $DirecSs[];
	$DirecSs[0]=<<1,0,0>>;
	$DirecSs[1]=<<0,0,1>>;
	float $St =1.0;

	float $Neg,$Posi,$NegB,$PosiB;
	int $C,$Cc,$ZO[];
	string $AllPolys[];
	int  $ABC[];


	int $Num;
	int $CornerN=0;
	int $SizeNc =`size($NumSq)`;
	int $Xn;
	if($SizeNc==3){
	$Xn=(((($NumSq[0]+1)+($NumSq[1]+1)+($NumSq[2]+1))-10)+1)*-1;
	}

	// print $Xn;

	if(($Xn==2)&&($SizeNc==3)){
	 $NumSq[0]=3;
	 $NumSq[1]=0;
	 $NumSq[2]=1;
	//$NumSq[0]=1;
	//$NumSq[1]=3;
	//$NumSq[2]=0;
	}else if(($Xn==1)&&($SizeNc==3)){
	$NumSq[0]=2;
	$NumSq[1]=3;
	$NumSq[2]=0;
	}else{
	$NumSq=sort($NumSq);
	}



	int $KeyN=1;
	int $Iin;
	int $NumSqT[];
	clear $NumSqT;
	$NumSqT = $NumSq;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	$NumSqT[$Iin]+=1;
	$KeyN*=$NumSqT[$Iin];
	}
	print $KeyN;
	if($SizeNc==2){
	if($KeyN==6){
	$NumSq[0]=$NumSq[1];
	$NumSq[1]=$NumSqT[0]-1;
	}

	if(($KeyN==2)||($KeyN==12)){
	$NumSq[0]=$NumSq[1];
	$NumSq[1]=$NumSqT[0]-1;
	}
	}

	int $DsqM = $Ndir2Sq[$KeyN];
	vector $EdgeTemp[];
	clear $EdgeTemp;
	if($SizeNc==1){
	$CornerN=1;
	}
	int $Tn=0;
	int $Iin;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	 $Num =$NumSq[$Iin];
	 $C=$Num;
	 $Cc=$Num;
	 $ABC[0]= int(fmod($C,4));
	$C++;
	 $ABC[1]= int(fmod($C,4));
	$C++;
	 $ABC[2]= int(fmod($C,4));
	$C++;
	 $ABC[3]= int(fmod($C,4));
	if($Num==0){
	$ZO[0]=0; $ZO[1]=1;
	 $Neg=-1.0; $Posi=1.0; $NegB=-1.0; $PosiB=1.0;
	}
	if($Num==1){
	$ZO[0]=1; $ZO[1]=0;
	 $Neg=1.0; $Posi=-1.0; $NegB=-1.0; $PosiB=1.0;
	}
	if($Num==2){
	$ZO[0]=0; $ZO[1]=1; 
	$Neg=1.0; $Posi=-1.0; $NegB=1.0; $PosiB=-1.0;
	}
	if($Num==3){
	$ZO[0]=1; $ZO[1]=0;
	 $Neg=-1.0; $Posi=1.0; $NegB=1.0; $PosiB=-1.0;
	}
	$EdgeV[0] = (($DirecSs[$ZO[0]]*$Neg)*($Fe *$St))+$ABvec[$Cc];
	$EdgeV[1] = (($DirecSs[$ZO[1]]*$NegB)*($Fe *$St))+$ABvec[$Cc];
	$EdgeV[2] = (($DirecSs[$ZO[0]]*$Posi)*($Fe *$St))+$ABvec[$Cc];
	$EdgeV[3] = (($DirecSs[$ZO[1]]*$PosiB)*($Fe *$St))+$ABvec[$Cc];
	//////////
	$EdgeV[4] = (($DirecS[$Cc])*($Fe *$St))+$EdgeV[0];
	//////////
	//////////
	$EdgeV[5] = ($EdgeV[0]+$EdgeV[1])/2.0;
	$EdgeV[6] = ($EdgeV[2]+$EdgeV[3])/2.0;
	//////////
	//////////
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeV[4],$EdgeV[0],$EdgeV[5],$ABvec[$ABC[0]]});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[0]],$EdgeV[6],$EdgeV[3],$EdgeV[4]});//cornera2
	PAUSE;
	if($CornerN==1){
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[1]],$EdgeV[0],$EdgeV[4], $ABvec[$ABC[2]]});
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[3]], $ABvec[$ABC[2]],$EdgeV[4],$EdgeV[3]});
	PAUSE;
	} 

	$EdgeTemp[$Tn++]=$EdgeV[0];
	$EdgeTemp[$Tn++]=$EdgeV[3];
	$EdgeTemp[$Tn++]=$EdgeV[4];
	$EdgeTemp[$Tn++]=$EdgeV[5];
	$EdgeTemp[$Tn++]=$EdgeV[6];
	//////////
	}



	if($CornerN!=1){

	if($SizeNc==4){
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[7],$EdgeTemp[0+5],$EdgeTemp[6+5],$EdgeTemp[7+5]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[0],$EdgeTemp[2],$EdgeTemp[2+5],$EdgeTemp[1+5] });
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2+15],$EdgeTemp[0+12],$EdgeTemp[2+5] ,$EdgeTemp[2]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[0+12],$EdgeTemp[2+15],$EdgeTemp[1+15] ,$EdgeTemp[10]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[1],$EdgeTemp[15],$EdgeTemp[17] ,$EdgeTemp[2]});
	PAUSE;
	}

	if($SizeNc==2){
	if($CornerN!=1){
	if(($KeyN==3)||($KeyN==8)){
	if($KeyN==3){
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[0],$ABvec[1],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2],$EdgeTemp[1],$ABvec[3],<<0,0,0>>});//cornera
	//
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2+5],$EdgeTemp[1+5],$ABvec[1],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2+5],$EdgeTemp[5],$ABvec[3],<<0,0,0>>});//cornera
	PAUSE;
	}
	if($KeyN==8){
	int $iN[];
	$iN[0]=3;
	$iN[1]=1;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[0],$ABvec[$ABC[$iN[0]]],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2],$EdgeTemp[1],$ABvec[$ABC[$iN[1]]],<<0,0,0>>});//cornera
	//
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2+5],$EdgeTemp[1+5],$ABvec[$ABC[$iN[0]]],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2+5],$EdgeTemp[5],$ABvec[$ABC[$iN[1]]],<<0,0,0>>});//cornera
	PAUSE;
	}

	}
	}
	}


	//////////////
	if($SizeNc==2){
	if(($KeyN!=3)&&($KeyN!=8)){


	vector $TempCS[];
	clear $TempCS;
	int $Sq=0;
	int $Iin;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	$TempCS[$Sq] =$EdgeTemp[(2+(5*$Iin))]+($DirecS[$DsqM]*$Fe);
	//Loc $TempCS[$Sq];
	$Sq++;
	}

	//Between///////
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[1],$EdgeTemp[5],$EdgeTemp[7]});//cornera
	//MIDDLE//
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$EdgeTemp[2],$EdgeTemp[7],$TempCS[1]});//cornera
	PAUSE;
	//OUTER////////
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[1],$EdgeTemp[7],$EdgeTemp[6],$ABvec[$ABC[3]]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[2]],$TempCS[0],$TempCS[1],$ABvec[$ABC[3]]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[2]],$EdgeTemp[0],$EdgeTemp[2],$TempCS[0]});//cornera
	PAUSE;
	//////////////
	//////////////////////////////////////////////////////////////
	}
	}

	if($SizeNc==3){
	$KeyN=0;
	int $NumSqT[];
	clear $NumSqT;
	$NumSqT = $NumSq;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	$NumSqT[$Iin]+=1;
	$KeyN+=$NumSqT[$Iin];
	}
	//Lone Vec $ABvec[$Xn];
	int $DsqM = $Ndir3Sq[$KeyN];
	int $Ad=0; 
	if($Xn==1){
	$Ad=10;
	}
	//print $Xn;
	vector $TempCS[]; clear $TempCS;
	$TempCS[0] =$EdgeTemp[2+$Ad]+($DirecS[$DsqM]*$Fe);
	// Loc $TempCS[0];

	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$EdgeTemp[2],$EdgeTemp[2+5],$EdgeTemp[2+5+5]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[0],$EdgeTemp[6],$EdgeTemp[7]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[7],$EdgeTemp[0+5],$EdgeTemp[6+5],$EdgeTemp[7+5]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$EdgeTemp[2],$EdgeTemp[1],$ABvec[$Xn]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$ABvec[$Xn],$EdgeTemp[0+10],$EdgeTemp[2+10]});
	PAUSE;
	}

	}
	PAUSE;

	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//END 2D CELL
	////////////////////////////////////////////////////////////////////////////////////////////////////////////




	proc  life_Make3d(int $x, int $y, int $gridPtsN, int $OnorOff[],int  $StatesCount,int $cycle){



	/*

	int $TTT[]= Index_NxNxN_GetGrid(751 ,  $gridX);
	int $gridPtsN=$gridX;
	//9, 7,$gridX,  $OnorOff
	int $x=$TTT[0]; int $y=$TTT[1];
	*/

	global vector $SQUARE_PLANE[];
	global string $CreatedItemG[];
	int $Point = Grid_NxNxN_GetIndex($x,$y,$gridPtsN);
	//select -r $CreatedItemG[$Point];
	//print $OnorOff[$Point];

	if($OnorOff[$Point]==1){
	string $TempPoints[]; 
	int $total=0;
	int $modCnt = 0;
		int $total,$minusx,$minusy,$plusy,$plusx ;
		int $GridXi = $gridPtsN; 
		int $GridYi = $gridPtsN; 
		int $GridZi = $gridPtsN;
		$plusx = ($x+1);
	 if($plusx > $GridXi-1){
	$plusx=-1;}
		 if($x >= 1){
		$minusx =  ($x-1);
		 }else{
		 $minusx = -1;
	}

		$plusy = ($y+1);
	 if($plusy > $GridXi-1){
	$plusy=-1;}
		 if($y >= 1){
		$minusy = ($y-1);
		 }else{
		 $minusy = -1;
		}

	//select -r $CreatedItemG[0] $CreatedItemG[2] $CreatedItemG[30];

		int $allIndexCA[];

	if($minusx!=-1){
	$allIndexCA[0] = Grid_NxNxN_GetIndex( $minusx,$y,$gridPtsN);
	}else{$allIndexCA[0] =-1;}

	if($plusx!=-1){
	$allIndexCA[1] = Grid_NxNxN_GetIndex( $plusx,$y,$gridPtsN);
	}else{$allIndexCA[1] =-1;}

	if($plusy!=-1){
	$allIndexCA[2] = Grid_NxNxN_GetIndex( $x,$plusy,$gridPtsN);
	}else{$allIndexCA[2] =-1;}

	if($minusy!=-1){
	$allIndexCA[3] = Grid_NxNxN_GetIndex( $x,$minusy,$gridPtsN);
	}else{$allIndexCA[3] =-1;}

	//future USE for finding corners
	//if(($minusx!=-1)&&($minusy!=-1)){
	//$allIndexCA[4] = Grid_NxNxN_GetIndex( $minusx,$minusy,$gridPtsN);
	//}else{$allIndexCA[4] =-1;}

	//print $allIndexCA; 

	int $NSEW[];
	int $CN=0;
	for($eachLocCA in $allIndexCA){
	if($eachLocCA!=-1){
	if( $OnorOff[$eachLocCA]==0){
	$NSEW[`size($NSEW)`]=$CN;
	}
	}else{
	$NSEW[`size($NSEW)`]=$CN;
	}
	$CN++;
	}
	//print $NSEW;


	vector $CellV = << $y, 0, $x >>;

	vector $S_P[]=$SQUARE_PLANE;
	int $CN=0;
	for($Vec in $SQUARE_PLANE){
	 $S_P[$CN]=$Vec+$CellV;
	$CN++;
	}


	int $Size =`size($NSEW)`;
	if($Size>0){


	for($Ii=0;  $Ii<$Size; $Ii++){

	 switch($NSEW[$Ii]) {
		case 0:
	makePolygonQUAD({$S_P[4],$S_P[5],$S_P[7],$S_P[6]});//z- W
	break;
		case 1:
	makePolygonQUAD({$S_P[0],$S_P[1],$S_P[3],$S_P[2]});//z+ E
	break;
		case 2:
	makePolygonQUAD({$S_P[5],$S_P[3],$S_P[1],$S_P[7]});//x+ N
	break;
		case 3:
	makePolygonQUAD({$S_P[2],$S_P[4],$S_P[6],$S_P[0]});//x- S
	break;
	}

	}

	}


	}

	}






	////////////////////////

	vector $ABvec[];

	vector $SQUARE_PLANE[];
	vector $ABvec[];
	$ABvec[0]=<<0.5, 0, -0.5>>;
	$ABvec[1]=<<-0.5, 0, -0.5>>;
	$ABvec[2]=<<-0.5, 0, 0.5>>;
	$ABvec[3]=<<0.5, 0, 0.5>>;



	vector $DirecSs[];
	$DirecSs[0]=<<1,0,0>>;
	$DirecSs[1]=<<0,0,1>>;
	vector $DirecS[];
	$DirecS[0]=<<0,0,1>>;
	$DirecS[1]=<<1,0,0>>;
	$DirecS[2]=<<0,0,-1>>;
	$DirecS[3]=<<-1,0,0>>;


	/////////////////////
	int $Ndir2Sq[];
	$Ndir2Sq[2]=0;
	$Ndir2Sq[3]=-1;
	$Ndir2Sq[4]=3;
	$Ndir2Sq[6]=1;
	$Ndir2Sq[8]=-1;
	$Ndir2Sq[12]=2;
	///////////////////////
	int $Ndir3Sq[];
	$Ndir3Sq[7]= 3;
	$Ndir3Sq[6]= 0;
	$Ndir3Sq[9]=1;
	$Ndir3Sq[8]=3;
	////////////////////

	float $Fe =1.0/3.0;
	vector $EdgeV[];
	vector $DirecSs[];
	$DirecSs[0]=<<1,0,0>>;
	$DirecSs[1]=<<0,0,1>>;
	float $St =1.0;

	float $Neg,$Posi,$NegB,$PosiB;
	int $C,$Cc,$ZO[];
	int $rndN;


	int $NumSqR[];
	clear $NumSqR;
	$NumSqR={0,1,2,3};

	string $AllPolys[];
	clear $AllPolys;
	int $RUNf =2;
	int  $ABC[];

	for($iR=0; $iR<$RUNf; $iR++){

	if(`size($AllPolys)`>0){
	select -r $AllPolys;
	PAUSE; 
	delete $AllPolys;
	clear $AllPolys;
	}

	int $RandSize =rand(1,5);
	int $TempR;
		$rndN = rand(0,4);
	$TempR=$NumSqR[$rndN];
	$NumSqR[$rndN]=$NumSqR[0];
	$NumSqR[0]=$TempR;
	//print ($NumSqR[0]+","+$NumSqR[1]+","+$NumSqR[2]+","+$NumSqR[3]);

	int $NumSq[];
	clear $NumSq;
	int $NI;
	for($NI=0; $NI<$RandSize; $NI++){
	$NumSq[$NI]=$NumSqR[$NI];
	}
	//

	//print $NumSq;

	int $Num;
	int $CornerN=0;
	int $SizeNc =`size($NumSq)`;
	int $Xn;
	if($SizeNc==3){
	$Xn=(((($NumSq[0]+1)+($NumSq[1]+1)+($NumSq[2]+1))-10)+1)*-1;
	}

	//print $Xn;

	if(($Xn==2)&&($SizeNc==3)){
	 $NumSq[0]=3;
	 $NumSq[1]=0;
	 $NumSq[2]=1;
	//$NumSq[0]=1;
	//$NumSq[1]=3;
	//$NumSq[2]=0;
	}else if(($Xn==1)&&($SizeNc==3)){
	$NumSq[0]=2;
	$NumSq[1]=3;
	$NumSq[2]=0;
	}else{
	$NumSq=sort($NumSq);
	}



	int $KeyN=1;
	int $Iin;
	int $NumSqT[];
	clear $NumSqT;
	$NumSqT = $NumSq;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	$NumSqT[$Iin]+=1;
	$KeyN*=$NumSqT[$Iin];
	}
	if($SizeNc==2){
	if($KeyN==6){
	$NumSq[0]=$NumSq[1];
	$NumSq[1]=$NumSqT[0]-1;
	}
	if(($KeyN==2)||($KeyN==12)){
	$NumSq[0]=$NumSq[1];
	$NumSq[1]=$NumSqT[0]-1;
	}
	}
	int $DsqM = $Ndir2Sq[$KeyN];
	vector $EdgeTemp[];
	clear $EdgeTemp;
	if($SizeNc==1){
	$CornerN=1;
	}
	int $Tn=0;
	int $Iin;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	 $Num =$NumSq[$Iin];
	 $C=$Num;
	 $Cc=$Num;
	 $ABC[0]= int(fmod($C,4));
	$C++;
	 $ABC[1]= int(fmod($C,4));
	$C++;
	 $ABC[2]= int(fmod($C,4));
	$C++;
	 $ABC[3]= int(fmod($C,4));
	if($Num==0){
	$ZO[0]=0; $ZO[1]=1;
	 $Neg=-1.0; $Posi=1.0; $NegB=-1.0; $PosiB=1.0;
	}
	if($Num==1){
	$ZO[0]=1; $ZO[1]=0;
	 $Neg=1.0; $Posi=-1.0; $NegB=-1.0; $PosiB=1.0;
	}
	if($Num==2){
	$ZO[0]=0; $ZO[1]=1; 
	$Neg=1.0; $Posi=-1.0; $NegB=1.0; $PosiB=-1.0;
	}
	if($Num==3){
	$ZO[0]=1; $ZO[1]=0;
	 $Neg=-1.0; $Posi=1.0; $NegB=1.0; $PosiB=-1.0;
	}
	$EdgeV[0] = (($DirecSs[$ZO[0]]*$Neg)*($Fe *$St))+$ABvec[$Cc];
	$EdgeV[1] = (($DirecSs[$ZO[1]]*$NegB)*($Fe *$St))+$ABvec[$Cc];
	$EdgeV[2] = (($DirecSs[$ZO[0]]*$Posi)*($Fe *$St))+$ABvec[$Cc];
	$EdgeV[3] = (($DirecSs[$ZO[1]]*$PosiB)*($Fe *$St))+$ABvec[$Cc];
	//////////
	$EdgeV[4] = (($DirecS[$Cc])*($Fe *$St))+$EdgeV[0];
	//////////
	//////////
	$EdgeV[5] = ($EdgeV[0]+$EdgeV[1])/2.0;
	$EdgeV[6] = ($EdgeV[2]+$EdgeV[3])/2.0;
	//////////
	//////////
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeV[4],$EdgeV[0],$EdgeV[5],$ABvec[$ABC[0]]});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[0]],$EdgeV[6],$EdgeV[3],$EdgeV[4]});//cornera2
	PAUSE;
	if($CornerN==1){
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[1]],$EdgeV[0],$EdgeV[4], $ABvec[$ABC[2]]});
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[3]], $ABvec[$ABC[2]],$EdgeV[4],$EdgeV[3]});
	PAUSE;
	} 

	$EdgeTemp[$Tn++]=$EdgeV[0];
	$EdgeTemp[$Tn++]=$EdgeV[3];
	$EdgeTemp[$Tn++]=$EdgeV[4];
	$EdgeTemp[$Tn++]=$EdgeV[5];
	$EdgeTemp[$Tn++]=$EdgeV[6];
	//////////
	}



	if($CornerN!=1){

	if($SizeNc==4){
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[7],$EdgeTemp[0+5],$EdgeTemp[6+5],$EdgeTemp[7+5]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[0],$EdgeTemp[2],$EdgeTemp[2+5],$EdgeTemp[1+5] });
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2+15],$EdgeTemp[0+12],$EdgeTemp[2+5] ,$EdgeTemp[2]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[0+12],$EdgeTemp[2+15],$EdgeTemp[1+15] ,$EdgeTemp[10]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[1],$EdgeTemp[15],$EdgeTemp[17] ,$EdgeTemp[2]});
	PAUSE;
	}

	if($SizeNc==2){
	if($CornerN!=1){
	if(($KeyN==3)||($KeyN==8)){
	if($KeyN==3){
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[0],$ABvec[1],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2],$EdgeTemp[1],$ABvec[3],<<0,0,0>>});//cornera
	//
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2+5],$EdgeTemp[1+5],$ABvec[1],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2+5],$EdgeTemp[5],$ABvec[3],<<0,0,0>>});//cornera
	PAUSE;
	}
	if($KeyN==8){
	int $iN[];
	$iN[0]=3;
	$iN[1]=1;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[0],$ABvec[$ABC[$iN[0]]],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2],$EdgeTemp[1],$ABvec[$ABC[$iN[1]]],<<0,0,0>>});//cornera
	//
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2+5],$EdgeTemp[1+5],$ABvec[$ABC[$iN[0]]],<<0,0,0>>});//cornera
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({<<0,0,0>>,$EdgeTemp[2+5],$EdgeTemp[5],$ABvec[$ABC[$iN[1]]],<<0,0,0>>});//cornera
	PAUSE;
	}

	}
	}
	}


	//////////////
	if($SizeNc==2){
	if(($KeyN!=3)&&($KeyN!=8)){


	vector $TempCS[];
	clear $TempCS;
	int $Sq=0;
	int $Iin;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	$TempCS[$Sq] =$EdgeTemp[(2+(5*$Iin))]+($DirecS[$DsqM]*$Fe);
	//Loc $TempCS[$Sq];
	$Sq++;
	}

	//Between///////
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[1],$EdgeTemp[5],$EdgeTemp[7]});//cornera
	//MIDDLE//
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$EdgeTemp[2],$EdgeTemp[7],$TempCS[1]});//cornera
	PAUSE;
	//OUTER////////
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[1],$EdgeTemp[7],$EdgeTemp[6],$ABvec[$ABC[3]]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[2]],$TempCS[0],$TempCS[1],$ABvec[$ABC[3]]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$ABvec[$ABC[2]],$EdgeTemp[0],$EdgeTemp[2],$TempCS[0]});//cornera
	PAUSE;
	//////////////
	//////////////////////////////////////////////////////////////
	}
	}

	if($SizeNc==3){
	$KeyN=0;
	int $NumSqT[];
	clear $NumSqT;
	$NumSqT = $NumSq;
	for($Iin=0; $Iin<$SizeNc; $Iin++){
	$NumSqT[$Iin]+=1;
	$KeyN+=$NumSqT[$Iin];
	}
	//Lone Vec $ABvec[$Xn];
	int $DsqM = $Ndir3Sq[$KeyN];
	int $Ad=0; 
	if($Xn==1){
	$Ad=10;
	}
	//print $Xn;
	vector $TempCS[]; clear $TempCS;
	$TempCS[0] =$EdgeTemp[2+$Ad]+($DirecS[$DsqM]*$Fe);
	// Loc $TempCS[0];

	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$EdgeTemp[2],$EdgeTemp[2+5],$EdgeTemp[2+5+5]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[2],$EdgeTemp[0],$EdgeTemp[6],$EdgeTemp[7]});//cornera
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$EdgeTemp[7],$EdgeTemp[0+5],$EdgeTemp[6+5],$EdgeTemp[7+5]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$EdgeTemp[2],$EdgeTemp[1],$ABvec[$Xn]});
	PAUSE;
	$AllPolys[`size($AllPolys)`]= makePolygonQUAD({$TempCS[0],$ABvec[$Xn],$EdgeTemp[0+10],$EdgeTemp[2+10]});
	PAUSE;
	}

	}
	PAUSE;

	}



	/////////////////////////NEW
	

	string $allRenderedF[];
	string $faceVsALL[] = `ls-sl-fl`;
	string $faceVs[];
	vector $newAddedVec[];
	int $indexF[] = {1,0,2,3};
	vector $newAddedVecC[];
	vector $ALLAddedVecC[];
	clear $ALLAddedVecC;
		int $i,$j  ;
		for( $j = 0 ; $j < `size($faceVsALL)` ; $j++ ) {
	select -r $faceVsALL[$j];
	ConvertSelectionToVertices;
	 $faceVs= `ls-sl-fl`;
	$newAddedVec = PointArrayT($faceVs);
	//print $newAddedVec;
	$newAddedVec=VectorClockWise($newAddedVec);
		for( $i = 0 ; $i < 4 ; $i++ ) {
	$ALLAddedVecC[`size($ALLAddedVecC)`]=$newAddedVec[$i];
	}
	//print $newAddedVec;
	//$allRenderedF[$j]=makePolygonQUAD($newAddedVec);
	PAUSE;
	}



	ConvertSelectionToVertices;
	 $faceVs= `ls-sl-fl`;
	$newAddedVec = PointArrayT($faceVs);
	print $newAddedVec;

	string $IndexKey;
	$IndexKey="";
	$IndexKey+=("{");
	int $VecIndex[];
	vector $Evec,$Ovec;
		for( $j = 0 ; $j < `size($ALLAddedVecC)` ; $j++ ) {
	$Evec=$ALLAddedVecC[$j];
	for( $i = 0 ; $i < `size($newAddedVec)` ; $i++ ) {
	$Ovec=$newAddedVec[$i];
	if(($Evec.x==$Ovec.x)&&($Evec.y==$Ovec.y)&&($Evec.z==$Ovec.z)){
	$VecIndex[$j]=$i;
	//print ($VecIndex[$j]+" ");
	$IndexKey+=($VecIndex[$j]+",");
	}
	}
	}

	$IndexKey+=("};");
	print $IndexKey;

	print $VecIndex;

	vector $BvecIndex[];
	for( $i = 0 ; $i < `size($newAddedVec)` ; $i++ ){
	print ("$EvecIndex["+$i+"]=<<"+$newAddedVec[$i]+">>;"+"\n");
	}

	/*

	/////////////////////////////////////////////// typeE
	{0,3,2,1,3,0,5,4,6,7,0,1,8,5,0,7,};
	$EvecIndex[0]=<<0.1666666716 0 -0.1666666716>>;
	$EvecIndex[1]=<<0.1666666716 0 -0.5>>;
	$EvecIndex[2]=<<0.3333333433 0 -0.6666666865>>;
	$EvecIndex[3]=<<0.5 0 -0.5>>;
	$EvecIndex[4]=<<0.6666666865 0 -0.3333333433>>;
	$EvecIndex[5]=<<0.5 0 -0.1666666716>>;
	$EvecIndex[6]=<<-0.5 0 -0.5>>;
	$EvecIndex[7]=<<-0.5 0 0.5>>;
	$EvecIndex[8]=<<0.5 0 0.5>>;

	/////////////////////////////////////////////// typeD
	{0,3,2,1,3,0,5,4,6,9,8,7,9,6,11,10,0,1,12,13,13,14,5,0,6,13,12,11,13,6,7,14,};
	$DvecIndex[0]=<<0.1666666716 0 -0.1666666716>>;
	$DvecIndex[1]=<<0.1666666716 0 -0.5>>;
	$DvecIndex[2]=<<0.3333333433 0 -0.6666666865>>;
	$DvecIndex[3]=<<0.5 0 -0.5>>;
	$DvecIndex[4]=<<0.6666666865 0 -0.3333333433>>;
	$DvecIndex[5]=<<0.5 0 -0.1666666716>>;
	$DvecIndex[6]=<<-0.1666666716 0 0.1666666716>>;
	$DvecIndex[7]=<<-0.1666666716 0 0.5>>;
	$DvecIndex[8]=<<-0.3333333433 0 0.6666666865>>;
	$DvecIndex[9]=<<-0.5 0 0.5>>;
	$DvecIndex[10]=<<-0.6666666865 0 0.3333333433>>;
	$DvecIndex[11]=<<-0.5 0 0.1666666716>>;
	$DvecIndex[12]=<<-0.5 0 -0.5>>;
	$DvecIndex[13]=<<0 0 0>>;
	$DvecIndex[14]=<<0.5 0 0.5>>;

	/////////////////////////////////////////////// typec
	{0,3,2,1,3,0,5,4,6,9,8,7,9,6,11,10,0,6,7,5,12,13,6,0,13,14,11,6,15,14,13,12,15,12,0,1,};
	$CvecIndex[0]=<<-0.1666666716 0 -0.1666666716>>;
	$CvecIndex[1]=<<-0.5 0 -0.1666666716>>;
	$CvecIndex[2]=<<-0.6666666865 0 -0.3333333433>>;
	$CvecIndex[3]=<<-0.5 0 -0.5>>;
	$CvecIndex[4]=<<-0.3333333433 0 -0.6666666865>>;
	$CvecIndex[5]=<<-0.1666666716 0 -0.5>>;
	$CvecIndex[6]=<<0.1666666716 0 -0.1666666716>>;
	$CvecIndex[7]=<<0.1666666716 0 -0.5>>;
	$CvecIndex[8]=<<0.3333333433 0 -0.6666666865>>;
	$CvecIndex[9]=<<0.5 0 -0.5>>;
	$CvecIndex[10]=<<0.6666666865 0 -0.3333333433>>;
	$CvecIndex[11]=<<0.5 0 -0.1666666716>>;
	$CvecIndex[12]=<<-0.1666666716 0 0.1666666716>>;
	$CvecIndex[13]=<<0.1666666716 0 0.1666666716>>;
	$CvecIndex[14]=<<0.5 0 0.5>>;
	$CvecIndex[15]=<<-0.5 0 0.5>>;

	/////////////////////////////////////////////// typeb
	{0,3,2,1,3,0,5,4,6,9,8,7,9,6,11,10,12,15,14,13,15,12,17,16,18,0,6,12,0,1,11,6,6,7,17,12,18,19,5,0,18,12,13,19,};
	$BvecIndex[0]=<<0.1666666716 0 -0.1666666716>>;
	$BvecIndex[1]=<<0.1666666716 0 -0.5>>;
	$BvecIndex[2]=<<0.3333333433 0 -0.6666666865>>;
	$BvecIndex[3]=<<0.5 0 -0.5>>;
	$BvecIndex[4]=<<0.6666666865 0 -0.3333333433>>;
	$BvecIndex[5]=<<0.5 0 -0.1666666716>>;
	$BvecIndex[6]=<<-0.1666666716 0 -0.1666666716>>;
	$BvecIndex[7]=<<-0.5 0 -0.1666666716>>;
	$BvecIndex[8]=<<-0.6666666865 0 -0.3333333433>>;
	$BvecIndex[9]=<<-0.5 0 -0.5>>;
	$BvecIndex[10]=<<-0.3333333433 0 -0.6666666865>>;
	$BvecIndex[11]=<<-0.1666666716 0 -0.5>>;
	$BvecIndex[12]=<<-0.1666666716 0 0.1666666716>>;
	$BvecIndex[13]=<<-0.1666666716 0 0.5>>;
	$BvecIndex[14]=<<-0.3333333433 0 0.6666666865>>;
	$BvecIndex[15]=<<-0.5 0 0.5>>;
	$BvecIndex[16]=<<-0.6666666865 0 0.3333333433>>;
	$BvecIndex[17]=<<-0.5 0 0.1666666716>>;
	$BvecIndex[18]=<<0.1666666716 0 0.1666666716>>;
	$BvecIndex[19]=<<0.5 0 0.5>>;


	/////////////////////////////////////////////// typeA

	{0,3,2,1,3,0,5,4,6,9,8,7,9,6,11,10,12,15,14,13,15,12,17,16,18,21,20,19,21,18,23,22,6,7,17,12,1,11,6,0,18,0,6,12,12,13,23,18,5,0,18,19,};

	$AvecIndex[0]=<<0.1666666716 0 -0.1666666716>>;
	$AvecIndex[1]=<<0.1666666716 0 -0.5>>;
	$AvecIndex[2]=<<0.3333333433 0 -0.6666666865>>;
	$AvecIndex[3]=<<0.5 0 -0.5>>;
	$AvecIndex[4]=<<0.6666666865 0 -0.3333333433>>;
	$AvecIndex[5]=<<0.5 0 -0.1666666716>>;
	$AvecIndex[6]=<<-0.1666666716 0 -0.1666666716>>;
	$AvecIndex[7]=<<-0.5 0 -0.1666666716>>;
	$AvecIndex[8]=<<-0.6666666865 0 -0.3333333433>>;
	$AvecIndex[9]=<<-0.5 0 -0.5>>;
	$AvecIndex[10]=<<-0.3333333433 0 -0.6666666865>>;
	$AvecIndex[11]=<<-0.1666666716 0 -0.5>>;
	$AvecIndex[12]=<<-0.1666666716 0 0.1666666716>>;
	$AvecIndex[13]=<<-0.1666666716 0 0.5>>;
	$AvecIndex[14]=<<-0.3333333433 0 0.6666666865>>;
	$AvecIndex[15]=<<-0.5 0 0.5>>;
	$AvecIndex[16]=<<-0.6666666865 0 0.3333333433>>;
	$AvecIndex[17]=<<-0.5 0 0.1666666716>>;
	$AvecIndex[18]=<<0.1666666716 0 0.1666666716>>;
	$AvecIndex[19]=<<0.5 0 0.1666666716>>;
	$AvecIndex[20]=<<0.6666666865 0 0.3333333433>>;
	$AvecIndex[21]=<<0.5 0 0.5>>;
	$AvecIndex[22]=<<0.3333333433 0 0.6666666865>>;
	$AvecIndex[23]=<<0.1666666716 0 0.5>>;
	//////////////////////////////////



	makePolygonQUAD({$TempCS[0],$EdgeTemp[2],$EdgeTemp[2+5],$EdgeTemp[2+5+5]});

8.553
148.760

*/
