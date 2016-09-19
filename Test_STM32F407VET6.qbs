import qbs
import qbs.FileInfo
import qbs.ModUtils

Project {
    qbsSearchPaths: "qbs"

    references: [
        "./CubeMX.qbs",
    ]
}
