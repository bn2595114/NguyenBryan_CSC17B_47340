function S1(pv,int,n){
    this.pv = pv;
    this.int = int;
    this.n = n;
}
function S2(pv,int,n){
    this.pv = pv;
    this.int = int;
    this.n = n;
}

function S3(pv,int,n){
    this.pv = pv;
    this.int = int;
    this.n = n;
}

function S4(pv,int,n){
    this.pv = pv;
    this.int = int;
    this.n = n;
}

function S5(pv,int,n){
    this.pv = pv;
    this.int = int;
    this.n = 12;
}

function S6(pv,int,n, fv){
    this.pv = pv;
    this.int = int;
    this.n = n;
	this.fv = fv;
}

function S7(pv,int,n){
    this.pv = pv;
    this.int = int;
    this.n = n;
}

function Display(){
}

//Savings with a for-loop
S1.prototype.save1=function(){
    for(var year=1;year<=this.n;year++){
        this.pv*=(1+this.int);
    }
    return this.pv;
};

//Savings with a power function
S2.prototype.save2 = function(){
    return this.pv*Math.pow((1+this.int),this.n);
};

//Savings with the exponential-log
S3.prototype.save3 = function(){
    return this.pv*Math.exp(this.n*Math.log(1+this.int));
};

//Savings with recursion
S4.prototype.save4 = function(){
    if(this.n<=0)return this.pv;
    return S4.prototype.save4(this.pv,this.int,this.n-1)*(1+this.int);
};

//Savings with a defaulted parameter
S5.prototype.save5 = function(){
    for(var year=1;year<=this.n;year++){
        this.pv*=(1+this.int);
    }
    return this.pv;
};

//Savings with a reference object
S6.prototype.save6 = function(){
    (this.fv).save=this.pv*Math.exp(this.n*Math.log(1+this.int));
};

//Savings with an array
S7.prototype.save7 = function(){
    //Declare an array
    var fv=new Array();
    //Calculate all the values in the array
    fv[0]=this.pv;
    for(var year=1;year<=this.n;year++){
        fv[year]=fv[year-1]*(1+this.int);
    }
    return fv;
};

//Display the savings array
Display.prototype.display = function(fv){
    //Output the heading for our table
    document.write('<table width="200" border="1">');
    document.write("<tr><th>Years</th><th>Savings</th></tr>");
    for(var year=0;year<fv.length;year++){
        document.write("<tr>");
        document.write("<td>"+year+"</td>");
        var x=1*fv[year];
        document.write("<td>$"+x.toFixed(2)+"</td>");
        document.write("</tr>");
    }
    document.write("</table>");	
};

