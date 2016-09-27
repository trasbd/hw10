https://sites.google.com/a/mst.edu/price/courses/cs-1570/hw/2016/spring/assignment-10

For this assignment, you will submit multiple files containing a program written in C++. Also, for this assignment you are going to be allowed to work in groups. You may form a group of no more than 2 individuals to work on assignments #10 together. This is NOT required; you can do this assignment on your own if you desire. There are two stipulations:

You will divide the work equitably. This means no sponging! Everyone codes, everyone documents, everyone tests.
Both individuals in a group have the same instructor, e.g. if one member is in Price's class, then they both are.
When you submit your work, submit under only one name, but be sure to put all names in the comment headers.
Background: background

Foreground: Here's the big picture. Your program is going to be a simulation of a sammich eating contest at Cletus's Sammich Shop! In brief, you will have an array of customers (the contestants) eating sammiches in multiple rounds of the contest to see who "survives". Sometimes there is a single winner (survivor) and sometimes there are more. You will identify the winners and their stats.

Specifications: In this assignment, you will use your classes from hw #9 and add another class:

A Sammichmeister class is to contain the following:

Member variables:
a name (presumably instantiated w/ "Cletus")
monetary holdings
Member functions:
a constructor that accepts a string for the object's name and monetary holdings.
an overloaded += operator that takes a float (representing money) and adds it to the sammichmeister's money. So, you might have Cletus += 5; meaning Cletus just made $5.
an overloaded -= operator (for similar purposes).
You may have other members/functions, but that's up to you to decide.

The Customer class will be modified to include a health value that the constructor will randomly assign between 1 and 100, inclusive. A value of 0 is synonymous with death and should not be assigned by the constructor. You may have to add other member variables and/or functions to this class.

The contest will proceed as follows: There will be as many rounds as is necessary, ending when there are no contestants still eating sammiches. You will start with an array of 15 customers; these are the contestants. In each round, every contestant is fed a sammich if (s)he can eat it. Being able to eat a sammich is determined by whether or not the contestant is alive, can pay for the sammich, and is still a contestant. After the start of the contest, a contestant can become a non-contestant by either dying or angering the sammichmeister so that (s)he disqualifies him/her (this is described later). When a contestant eats a sammich, (s)he pays the sammichmeister -- ok, I'm going to call him Cletus and you really should too -- the cost of the sammich. Now things get interesting. As in hw 9, the customer's weight and cholesterol are adjusted accordingly. In addition, their health value is decremented by 2 points. Also, if a sammich with a virulent pathogen is consumed, then the customer will either die or sicken and vomit. To determine which, "roll a 100-sided die"; if the value that comes up is greater than the customer's health value, they die; if the value is equal to or less than his/her health value, they vomit and their health is halved. If a contestant (let's call him Alpha) vomits, then there is a 50% 30% chance that his neighbors will also vomit. So, if Alpha vomits, your code will have to first walk down the array of contestants determining (with a 50% 30% chance) if the next contestant vomits....and if so, then the next....and if so, then the next....until you reach the bottom end of the array or someone doesn't vomit or the next guy/gal is dead. (Note: even alive non-contestants can puke.) After walking down the array, you will need to walk up the array doing the same until reaching the top of the array or someone doesn't vomit or you reach a dead contestant (thank God dead guys don't puke!). Now, in both cases (going down and going up), if the chain-reaction vomiting ends by someone just not vomiting, then that contestant has a 70% 90% chance of starting a food fight. This means that (s)he throws a sammich at another contestant or Cletus. Their target is chosen at random and can include themselves (stupid, yes, how stupid can you get - eating roadkill at Cletus's restaurant!). When another contestant is hit by a sammich, they have a 80% chance of continuing the fight by randomly choosing a target and throwing a sammich. Each thrown sammich has to be paid for by the thrower, but the thrower's health increments by 2 points. The food fight stops when someone decides not to throw, can't afford the sammich to throw, a dead contestant is the target, or if Cletus is hit. If Cletus is hit, he gets angry and disqualifies the guy who hit him with a sammich, and robs the thrower of all his cash. After the food fight ends 1) in the lower end of the array, continue checking for pukers in the upper end of the array; 2) in the upper end of the array, continue to the next round of feeding!

Details:

The sammich that the contestants eat or throw are created "on the fly". That doesn't mean that they have flies on them (but probably do since they are Cletus's roadkill fare). It means that your code will create a sammich in that scope and the customer will eat() it or toss() it.1 (This is opposed to the concept of having, say, an array of sammiches from which the contestants eat().)
There are two ways for a contestant to be disqualified (become a non-contestant). One is that he hits Cletus with a sammich. You might find this unfortunate. But look at the positive side: they avoid exploding from eating too much, dying of a heartattack, and eating a pathogen. The other way is to die during the contest. Note: just because a contestant fails to eat during a round because they can't afford the sammich, doesn't disqualify them.
If a contestant eats a contaminated sammich, his health value is halved. Of course, if he dies then who cares.
There are 4 ways for a contestant to die.
their weight gain during the contest is 80 lbs or more - bursting is a terrible way to go.
their cholesterol exceeds 300, resulting in a heartattack.
their health level goes to 0. ..... Bummer.
they eat a tainted sammich.....really tainted.
The sammichmeister shall be Cletus. Any other name would indicate that you just don't get it.
Cletus will start with $100 at the beginning of the contest.
No customer is to weigh less than 50lb nor more than 500lb.  In either case, they are to be declared dead.
Cletus collects the price of each sammich. But, Cletus has to pay $5 $1 each time a contestant vomits, and pays $35 $5 every time a contestant dies during the contest ($30  $3.50 for body disposal, $5 $1.50 for flowers for the bereaved).
If Cletus is hit with a sammich, he not only disqualifies the thrower, but also steals all his money.
The contest can end with one contestant still alive but hasn't eaten sammiches for a round or more. This happens when they can't afford the sammich given them and the others can, eating until their deaths. Running out of money can be a good strategy! Alternatively, there may be two or more still living at the end,and in this case, the winner is the one who ate the most sammiches. If they have eaten the same number, the winner is the contestant who gained the most weight.
Your output: Make your output of sammiches fit on one line if possible. Likewise with a customer. Put "DEAD" at the end of the output of a customer if they are indeed dead.
Now, for the contest, output a line of dashes between every round. Begin by outputting the list of contestants before anything happens. And, as the contest proceeds, output only the contestants that are eating, and then the sammich they ate in that round. Indent the sammich 2 spaces so it's easier to read. Anytime a contestant pukes, (s)he must "say" something - create a file of "barf calls" that you randomly choose from (you can make them up). But it should be indented several spaces after the sammich and should be of this format: "Homer pukes....BLAHHH GLPRP", i.e. include the name. Anytime a contestant throws a sammich, (s)he also has to say something. Implement this any way you want; format the output similar to the puke-call.
After the last round, identify the surviving contestants along with their stats. Proclaim a winner. Also, output Cletus's state - how much money he made or lost, whether or not he went broke, etc.
Any other output you come up with that makes this fun to see, go ahead and include it.
When you submit: Run the simulation once.

As always, if you have questions, don't hesitate to ask your instructor or the tutor in the lab in the evenings. 

1DON'T use the word 'throw' for a function name since it is a reserved word.