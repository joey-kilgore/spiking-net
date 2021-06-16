library(ggplot2)
library(reshape)

init_data <- read.csv("../data/cells.csv", header=FALSE)
cell_names <- c("Time","C0","C1","C2","C3","C4","C5","C6","C7","C8","C9")
names(init_data) <- cell_names
cells <- subset(init_data, select=cell_names)
cells <- melt(cells, id=c("Time"))

cellPlot <- ggplot(data=cells)+geom_line(aes(x=Time,y=value,color=variable))
ggsave(filename="cell.png",plot=cellPlot, height=5, width=5)

synapse_data <- read.csv("../data/synapses.csv", header=FALSE)
synapse_data <- synapse_data[c(0,-102)]
synapse_melt <- melt(synapse_data, id=c("V1"))
synapse_plot <- ggplot(data=synapse_melt)+geom_line(aes(x=V1, y=value, color=variable))
ggsave(filename="synapse.png",plot=synapse_plot, height=5, width=10)
