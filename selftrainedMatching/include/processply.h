#ifndef PROCESSPLY_H
#define PROCESSPLY_H
#include <C:\Software\VS2013\PCL\include\pcl\io\ply_io.h>
#include <C:\Software\VS2013\PCL\include\pcl\point_types.h>
#include <pcl/filters/filter.h>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
class Pointcloud
{
public:
    Pointcloud();
    void processply();
    void changeColorToGreen();
    void removeOutlyers();
    void setPath(boost::filesystem::path input){m_path= input;}
    void setLuxorCloudsDirectory(boost::filesystem::path input);
    void setLuxorCloudsDirectory();
    void readply();
protected:
    boost::filesystem::path m_luxor_clouds_directory; // directory to folder where clouds are stored
    boost::filesystem::path m_path; //output cloud path
    pcl::PointCloud<pcl::PointXYZRGB> m_cloud;
};

boost::filesystem::path findLatestFile(boost::filesystem::path directory);
void clearDirectory(boost::filesystem::path path);
#endif // PROCESSPLY_H
