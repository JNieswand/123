#include <iostream>
#include <pcl\io\ply_io.h>
#include <pcl/filters/filter.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl\point_types.h>
#include <string>
#include <processply.h>



Pointcloud::Pointcloud(){

}

void Pointcloud::setLuxorCloudsDirectory(){
    m_luxor_clouds_directory = m_path.parent_path() / boost::filesystem::path("luxor_clouds");
}
void Pointcloud::setLuxorCloudsDirectory(boost::filesystem::path input){
    m_luxor_clouds_directory= input;
}


void Pointcloud::readply(){
    //read pointcloud to be converted
    boost::filesystem::path path = findLatestFile(m_luxor_clouds_directory);
    if (pcl::io::loadPLYFile<pcl::PointXYZRGB>(path.string(), m_cloud)== -1) //* load the file
      {
        std::cout <<"Couldn't read file "<<path<<" \n";
        return;
      }
    std::cout << "Loaded "
              << m_cloud.width<<" * "<< m_cloud.height<< " = "
              << m_cloud.width * m_cloud.height
              << " data points from "<<path
              << std::endl;
}
void Pointcloud::processply(){
    readply();
    std::vector<int> vec;
    pcl::removeNaNFromPointCloud(m_cloud, m_cloud, vec);
    changeColorToGreen();
    removeOutlyers();
    std::cout << "new pointcloud is saved at "
              << m_path
              << "\n and has size"
              << m_cloud.points.size()
              <<std::endl;
    pcl::io::savePLYFileBinary(m_path.string(), m_cloud);
    clearDirectory(m_luxor_clouds_directory);
    return;
}

void Pointcloud::removeOutlyers(){
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudPTR(new pcl::PointCloud<pcl::PointXYZRGB>);
    *cloudPTR = m_cloud;
    // Create the filtering object
     pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
     sor.setInputCloud (cloudPTR);
     sor.setMeanK (50);
     sor.setStddevMulThresh (1.0);
     sor.filter (m_cloud);
     return;
}
void Pointcloud::changeColorToGreen(){
    for(size_t i=0; i< m_cloud.points.size(); i++){
        m_cloud.points[i].g = 255;
        m_cloud.points[i].b = 0;
        m_cloud.points[i].r = 0;
    }
    return;
}



boost::filesystem::path findLatestFile(boost::filesystem::path directory)
{
    boost::filesystem::path latest;
    std::time_t latest_tm {};
    for(auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(directory), {}, {})) {
        boost::filesystem::path p = entry.path();
        if (is_regular_file(p) && p.extension() == ".ply")
        {
            std::time_t timestamp = boost::filesystem::last_write_time(p);
            if (timestamp > latest_tm) {
                latest = p;
                latest_tm = timestamp;
            }
        }
    }

    if (latest.empty()){
        std::cout << "Nothing found\n";
    }
    else{
        std::cout << "Last modified: " << latest.string() << "\n";
    }
    return latest;
}

void clearDirectory(boost::filesystem::path path){
    for (boost::filesystem::directory_iterator end_dir_it, it(path); it!=end_dir_it; ++it) {
        boost::filesystem::remove_all(it->path());
      }
    std::cout << "Cleared directory:\n"
              << path.string()
              <<"\n";
}


