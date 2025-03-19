var db;
db = new PouchDB("contact_db");


function addContact()
{
var full_name = document.getElementById("full_name").value;
var email = document.getElementById("email").value;
var HNum = document.getElementById("HNum").value;
var CNum = document.getElementById("CNum").value;
HNum = HNum.replace(/(\d{3})(\d{4})/, "$1-$2");
CNum = CNum.replace(/(\d{3})(\d{4})/, "$1-$2");
if (document.getElementById('BusC').checked)
{
 var TC1 = document.getElementById('BusC').value;
}
else if (document.getElementById('PerC').checked)
{
 var TC1 = document.getElementById('PerC').value;
}

var contact = { 
				_id: new Date().toISOString(),
				name: full_name,
				email: email,
				HNum: HNum,
				CNum: CNum,
				TC1: TC1
				};
db.put(contact, function callback(err, result)
{
if (!err)
{
console.log('Successfully saved a contact!');
alert ("Record added!!");
}
});
}

function showContacts()
{
	db.allDocs({include_docs: true}, function(err, docs)
	{
	if (err)
	{
		return console.log(err);
	}
	else
	{
		var num_records=docs.total_rows;
		var display_records="";
		for(var i = 0; i < num_records; i++)
		{
			display_records = display_records + "Contact Name: " + docs.rows[i].doc.name + "<br/>" +"Email: " + docs.rows[i].doc.email + "<br/>"+ "Home Number: "+ docs.rows[i].doc.HNum + "<br/>" + "Cell Number: "+ docs.rows[i].doc.CNum +"<br/>" + "Type of Contact: "+ docs.rows[i].doc.TC1+ "<hr/>";
		}
		document.getElementById("contact_list").innerHTML = display_records;
	}
	});
}

function delContacts()
{
	db.destroy(function (err, response)
	{
		if (err)
		{
			return console.log(err);
		}
		else
		{
			console.log ("Database Deleted");
		}
    });
}

function countContacts()
{
    db.allDocs({include_docs: true}, function(err, docs)
    {
        if (err)
        {
            return console.log(err);
        }
        else
        {
            var num_records = docs.total_rows;
            var display_records="";
            var rando = 0;
            var rando2 = 0;
            var i = 0;
            for(i = 0; i < num_records; i++)
            {
                display_records = docs.rows[i].doc.TC1;
                if (display_records == "Business")
                {
                    rando++;
                }
                else if (display_records == "Personal")
                {
                    rando2++;
                }
            }
        }

        document.getElementById("contact_count").innerHTML ="The Number of Business Contacts is " + rando;
        document.getElementById("contact_count2").innerHTML ="The Number of Personal Contacts is " + rando2;
});
}

function editContacts()
{
	var contact = document.getElementById("contacts").value;
	
	var full_name = document.getElementById("full_name").value;
	var email = document.getElementById("email").value;
	var HNum = document.getElementById("HNum").value;
	var CNum = document.getElementById("CNum").value; 
	HNum = HNum.replace(/(\d{3})(\d{4})/, "$1-$2");
	CNum = CNum.replace(/(\d{3})(\d{4})/, "$1-$2");			
	if (document.getElementById('BusC').checked)
	{
		var TC1 = document.getElementById('BusC').value;
	}
	else if (document.getElementById('PerC').checked)
	{
		var TC1 = document.getElementById('PerC').value;
	}
	
	db.allDocs({include_docs: true}, function(err, docs)
	{	
		db.get(contact, function(err, doc)
		{
			if(err)
			{
				return console.log(err);
			}
			else 
			{	
				var revid = doc._rev;
				var con_id = doc._id;
				
				var updContact = {
					_id: con_id,
					name: full_name,
					_rev: revid,
					email: email,
					HNum: HNum,
					CNum: CNum,
					TC1: TC1
				};
				
				db.put(updContact, function callback(err, result)
				{
					if (err)
					{
						alert("error");
						
					}
					else
					{
						console.log('Successfully updated!');
						alert ("Record Updated!!");
					}
				});
			}
		});
	});
}

function lookupContact()
{
	var contact = document.getElementById("contacts").value;
  
	db.get(contact, function(err, doc)
	{
		if(err)
		{
			return console.log(err);
		}
		else 
		{
			var display_record = "Contact Name: " + doc.name + "<br/>" +"Email: " + doc.email + "<br/>"+ "Home Number: "+ doc.HNum+ "<br/>" + "Cell Number: "+ doc.CNum +"<br/>" + "Type of Contact: "+ doc.TC1+ "<hr/>";
		
			document.getElementById("contacts_spinner").innerHTML = display_record;
		}
    });
}

function spinner()
{
 
	db.allDocs({include_docs: true}, function(err, docs) {
     
    if (err) 
	{
		return console.log(err);
    } 
	else
	{
		var num_records=docs.total_rows;
		var list_start = "<select name ='contacts' id='contacts'>";
		var list_end = "</select>";
		var list_contacts = " ";
		for(var i = 0; i < num_records; i++)
		{
			list_contacts = list_contacts + "<option value=" + docs.rows[i].doc._id + " '> " + docs.rows[i].doc.name + "</option>";
		}
		
		document.getElementById("select").innerHTML = list_start +  list_contacts+ list_end;
		
	}
});
}
 const menuBtn = document.querySelector('.menu-btn');
let menuOpen = false;
menuBtn.addEventListener('click',() => {
	if(!menuOpen){
		menuBtn.classList.add('open');
		menuOpen = true;	
	}
	else{
		menuBtn.classList.remove('open');
		menuOpen = false;	
	}
});
