library(ggplot2)
library(reshape)

print("PLOT GENERATOR")
print("--help for more options")

args <- commandArgs()
if(length(args)<6){
	stop("THE FIRST ARG MUST BE A CSV FILE PATH")
}

if(args[6]=="--help"){
	print("first arg must be a csv file in the form of")
	print("time step, val1, val2, etc,")
	print("")
	print("second arg must be the first val to plot")
	print("")
	print("third arg must be the last val to plot")
	stop("")
}

if(length(args)<7){
	stop("ADDITIONAL ARG MUST BE LSITED FOR WHICH VAL TO PLOT")
}

print("READING DATA...")
print(args[6])
init_data <- read.csv(file=args[6],header=FALSE)

print("MANIPULATING DATA...")
vals <- append(c(1),seq(as.numeric(args[7])+1,as.numeric(args[8])+1))
data <- init_data[,vals]
data_melt <- melt(data, id=c("V1"))

print("CREATING PLOT...")
plot <- ggplot(data=data_melt)+geom_line(aes(x=V1,y=value,color=variable))
ggsave("./analysis/plot.png",plot)
