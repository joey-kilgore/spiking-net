library(ggplot2)
library(reshape)

init_data <- read.csv("../data/cells.csv", header=FALSE)
cell_names <- c("Time","C0","C1","C2","C3","C4","C5","C6","C7","C8","C9")
names(init_data) <- cell_names
cells <- subset(init_data, select=cell_names)
cells <- melt(cells, id=c("Time"))

cellPlot <- ggplot(data=cells)+geom_line(aes(x=Time,y=value,color=variable))
ggsave(filename="cell.png",plot=cellPlot, height=5, width=5)
