/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: Dept of Mechanical Engineering, MIT, Cambridge MA    */
/*    FILE: PlatModel.h                                          */
/*    DATE: July 26th, 2023                                      */
/*                                                               */
/* This file is part of IvP Helm Core Libs                       */
/*                                                               */
/* IvP Helm Core Libs is free software: you can redistribute it  */
/* and/or modify it under the terms of the Lesser GNU General    */
/* Public License as published by the Free Software Foundation,  */
/* either version 3 of the License, or (at your option) any      */
/* later version.                                                */
/*                                                               */
/* IvP Helm Core Libs is distributed in the hope that it will    */
/* be useful but WITHOUT ANY WARRANTY; without even the implied  */
/* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR       */
/* PURPOSE. See the Lesser GNU General Public License for more   */
/* details.                                                      */
/*                                                               */
/* You should have received a copy of the Lesser GNU General     */
/* Public License along with MOOS-IvP.  If not, see              */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/

#ifndef PLAT_MODEL_HEADER
#define PLAT_MODEL_HEADER

#include <vector>
#include <string>
#include "XYPoint.h"
#include "XYSeglr.h"

class PlatModel 
{
 public:
  PlatModel();
  PlatModel(double osx, double osy, double osh);
  ~PlatModel() {};

public: // Setters (Pose)
  void setOSX(double v) {m_osx=v; m_osx_set=true;}
  void setOSY(double v) {m_osy=v; m_osy_set=true;}
  void setOSH(double v);
  void setPose(double osx, double osy, double osh);

public: // Setters (Info typically set by a TMGen)
  bool setStarSpokes(const std::vector<double>&,
		     const std::vector<double>&);
  bool setPortSpokes(const std::vector<double>&,
		     const std::vector<double>&);

  void setStarSeglrs(const std::vector<XYSeglr>&);
  void setPortSeglrs(const std::vector<XYSeglr>&);
  void setSpokeDegs(double v) {m_spoke_degs=v;}
  
public: // Setters (Typically set by a user, e.g, ObShipModel)
  
  void setCache(bool, unsigned int, double);
  void setCache(bool, unsigned int, XYPoint);
  
public: // Getters configs
  double getOSX() const {return(m_osx);}
  double getOSY() const {return(m_osy);}
  double getOSH() const {return(m_osh);}
  double getDblValue(std::string) {return(0);}
  std::string getStrValue(std::string) {return("");}

public: // Getters (Model guts)
  std::vector<XYPoint> getPoints(std::string);
  XYSeglr getTurnSeglr(double hdg) const;
  
public: // Getters of state
  bool    valid() const;
  
  std::string getSpec() const;

  void print() const;
  
  void printSeglrCache(std::string tag) const;
  
protected: // Config vars
  double m_osx;
  double m_osy;
  double m_osh;
  bool   m_osx_set;
  bool   m_osy_set;
  bool   m_osh_set;  

  double m_spoke_degs;
  
  // Vector ix corresponds to one unit m_spoke_degs
  std::vector<double>  m_star_spoke_vx;
  std::vector<double>  m_star_spoke_vy;
  std::vector<double>  m_port_spoke_vx;
  std::vector<double>  m_port_spoke_vy;
  std::vector<XYSeglr> m_star_seglrs;
  std::vector<XYSeglr> m_port_seglrs;
};

PlatModel stringToPlatModel(std::string);

#endif 





