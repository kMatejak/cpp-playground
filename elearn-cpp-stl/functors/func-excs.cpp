/*
FUNCTORS

TASK 1
	Implement function object which checks if given number is odd
	Implement function object which checks if given number is divisible by other given number
	i.e. IsDivisible(2)(4) should return true
	Create vector with values 0..99 and print its contents
	Delete all odd values, then delete all values which are divisible by 3
	Delete all prime numbers from vector
	
TASK 2 - lambdas
	Implement lambda generator which creates values divisible by 7
	Implement lambda predicate which checks if value is divisible by 3
	Generate in loop 10 values using implemented generator. Print all elements which fulfill predicate.
	
TASK 3 - message handler
	Create simple class MessageHandler which will have two methods:
	addHandlerFor(messageType, functor_for_handling_messageData) - adding handler function to messageType
	handle(messageType, messageData) - calling proper handler based on messageType
	Use std::map as storage for handlers 
*/