function myFunction(){
let Tnails = document.forms[0];
let txt = "";
let i;
var sum =0;
for(i=0;i < Tnails.length;i++){
if(Tnails[i].checked){
txt = txt + Tnails[i].value+"";

}

}
var TF = document.forms[0];
var txt1 = "";
var y;


for(y=0;y < TF.length;y++){
if(TF[y].checked){
txt1 = txt1 + TF[y].value+"";

}
 
}
if (txt == "Hard Gell Fullsets - Long") {
	
	    sum = sum +110; 
	
	 }
 
else if (txt == "Hard Gell Fullsets - medium"){
	
	  sum = sum + 100;
	  
	 }
	 else if (txt == "Hard Gell Fullsets - short"){
	
	   sum = sum + 90;
	  
	 }
else if (txt == "Hard Gell Fullsets - Refills"){
	 
	   sum = sum + 70;	 
	 }	
else if (txt == "Acrylic Fullsets - Long"){
	
	  sum = sum +85;
	  
	 }		 
else if (txt == "Acrylic Fullsets - meduim"){
	
	   sum = sum + 75;
	  
	 }	

else if (txt == "Acrylic Fullsets - short"){
	
	   sum = sum +65;
	
	 }	
else if (txt == "Acrylic Fullsets - Refills"){
	
	   sum = sum +60;	
	 
	 }	 
else if (txt == "Gel Polish Only - Hands"){
	
	   sum = sum + 35;	
	
	 }	 

else if (txt == "Gel Polish Only - Toes"){
	
	  sum = sum + 35;
	
	 }	 

else if (txt == "Gel Polish Only - Toes And Hands"){
	  sum = sum +70;
	 
	 }	 


else if (txt1 == 'Hard Gell Fullsets - Longon'){
	
	sum = '160';
	
}

else if (txt1 == 'Hard Gell Fullsets - mediumon'){
	
	sum = '150';
	
}
else if (txt1 == 'Hard Gell Fullsets - shorton'){
	
	sum = '140';
	
}
else if (txt1 == 'Hard Gell Fullsets - Refillson'){
	
	sum = '120';
	
}
else if (txt1 == 'Acrylic Fullsets - Longon'){
	
	sum = '135';
	
}
else if (txt1 == 'Acrylic Fullsets - meduimon'){
	
	sum = '125';
	
}

 else if (txt1 == 'Acrylic Fullsets - shorton'){
	
	sum = '115';
	
}
else if (txt1 == 'Acrylic Fullsets - Refillson'){
	
	sum = '110';
	
}
else if (txt1 == 'Gel Polish Only - Handson'){
	
	sum = '85';
	
}
else if (txt1 == 'Gel Polish Only - Toeson'){
	
	sum = '85';
	
}
else if (txt1 == 'Gel Polish Only - Toes And Handson'){
	
	sum = '120';
	
}

document.getElementById("result").innerHTML='$ '+sum;
}