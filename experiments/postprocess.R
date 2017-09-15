setwd("")



x = data[1:150, 4]
y = data[1:150, 5]
yU = dataU[1:150, 4]
yU = dataU[1:150, 5]

w = y[1]
y = y /w
yU = yU/w

g = ggplot()

# plot results for greedy
g <- g + geom_point(aes(x = x, y = y, colour = "(1+1)EA"), alpha = 0.3)
g <- g + geom_point(aes(x = x, y = yU, colour = "(1+1)EA with restarts"), alpha = 0.3)
g <- g + geom_line(aes(x = x, y = y, colour = "(1+1)EA"))
g <- g + geom_line(aes(x = x, y = yU, colour = "(1+1)EA with restarts"))

# legends
cbbPalette <- c("#009E73", "#E69F00")
#cbbPalette <- c("#66CC99", "#CC6666")
g <- g + xlab("time budegt [calls to fitness]")
g <- g + ylab("solution quality in % [sample mean]")
g <- g + scale_colour_manual(name = "Algorithm", values = cbbPalette, labels=c("(1+1)EA", "(1+1)EA with restarts"))
g <- g + scale_shape_manual(name = "Algorithm", values=c(0, 2), labels = c("(1+1)EA", "(1+1)EA with restarts"))

# theme
g <- g + theme_bw()
g <- g + theme(panel.grid.major = element_line(colour = "#999999"))
g <- g + theme(panel.grid.minor = element_line(colour = "#666666", linetype = "dotted"))
g <- g + theme(panel.border = element_rect(colour = "black"))
g <- g + theme(legend.position = c(0.70, 0.88))
g <- g + theme(legend.text = element_text(size = 14))
g <- g + theme(legend.title = element_text(size=14, face = "bold"))
g <- g + theme(legend.background = element_rect(colour = "black"))

# vertical lines
g <- g + geom_vline(xintercept = 1200, linetype = "dotdash")
g <- g + geom_vline(xintercept = 12100, linetype = "dotdash")
g <- g + geom_vline(xintercept = 2600, linetype = "dotdash")

# save plot
pdf("thirdFourthExperiment.pdf", width = 6.5, height = 5.5)
g
dev.off()