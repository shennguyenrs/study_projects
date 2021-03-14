import java.io.File

fun main(args : Array<String>) {
    val filename = "numbers.txt"
    var file = File(filename)
    file.createNewFile()

    while(true){
        println("Type a positive integer (-1 to exit):")
        val num = readLine()!!.toInt()
        if (num < -1) {
            println("The number must be positive")
            continue
        }
        if(num==-1) break
        file.appendText(num.toString()+"\n")
    }

    val nums = mutableListOf<Int>()
    val str = file.readLines()
    str.forEach { ln -> nums.add(ln.toInt()) }
    println("You typed ${nums.count()} numbers.")
    println("The average is ${nums.average()}")
}