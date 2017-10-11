/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function CADD(){
     //Create an array with 2 objects
            var inventoryItem1={"Product":"Chicken","Inventory":"155","Price":"3.55"};
            var inventoryItem2={"Product":"Milk","Inventory":"203","Price":"2.33"};
            var inventory=[];
            inventory[0]=inventoryItem1;
            inventory[1]=inventoryItem2;
            //Display the array
            for(var items=0;items<inventory.length;items++){
                document.write("The "+items+" Object</br>");
                var obj=inventory[items];
                for(var property in obj){
                    document.write(property+"="+obj[property]+"</br>");
                }
            }
            //Stringify the array
            var str=JSON.stringify(inventory);
            //Store into local Storage
            this.inv=localStorage.setItem("Inventory",str);
            this.inv=localStorage.getItem("Inventory");
}

CADD.prototype.addInv=function(){
     //Get the information from the local URL
    var url=document.location.href;
    //Call the getForm function to place into an object
    var $_GET=getForm(url);
    //Retrieve from Inventory (load localstorage file)
    var str=localStorage.getItem("Inventory");
    //Parse the inventory to an object
    var inventory=JSON.parse(str);
    //How many products are in inventory
    var number=inventory.length;
    //Add our new product to inventory
    inventory[number]=$_GET;
    //Put back the object into local storage after adding to the inventory object
    var str=JSON.stringify(inventory);
    localStorage.setItem("Inventory",str);
    this.inv=localStorage.getItem("Inventory");
    //Display the array of objects
    this.display();
};

CADD.prototype.display=function(){
    //Parse the information back into an array
    var inventory=JSON.parse(this.inv);
    //Display the array
    var product="<h3>Inventory Items: <br></h3>";
    for(var items=0;items<inventory.length;items++){
        product+=("<strong>Object Number: "+items+" </strong></br>");
        var obj=inventory[items];
        for(var property in obj){
            product+=(property+"="+obj[property]+"</br>");
    }
    }
    document.getElementById("dsply").innerHTML = product;
};

CADD.prototype.remove=function(){
    //Get the information from the local URL
    var url=document.location.href;
    //Parse the URL to get item number to delete
    var delet=del(url);
    //Load inventory from local storage
    var str=localStorage.getItem("Inventory");
    //Create inventory object
    var inventory=JSON.parse(str);
    var temp=[];
    var size=inventory.length;
    for(var index=0;index<(size-1);index++){
        var newitem=index;
        if (index>=delet) {
            newitem=index+1;
        } 
        temp[index]=inventory[newitem];
    }
    str=JSON.stringify(temp);
    localStorage.setItem("Inventory",str);
    this.inv=localStorage.getItem("Inventory");
    this.display();
};

var inventory = new CADD();
