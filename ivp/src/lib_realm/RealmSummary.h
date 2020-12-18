/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: RealmSummary.h                                       */
/*    DATE: Dec 9th 2020                                         */
/*                                                               */
/* This file is part of MOOS-IvP                                 */
/*                                                               */
/* MOOS-IvP is free software: you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation, either version  */
/* 3 of the License, or (at your option) any later version.      */
/*                                                               */
/* MOOS-IvP is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty   */
/* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See  */
/* the GNU General Public License for more details.              */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with MOOS-IvP.  If not, see                     */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/

#ifndef REALM_SUMMARY_HEADER
#define REALM_SUMMARY_HEADER

#include <string>
#include <map>

class RealmSummary
{
 public:
  RealmSummary() {};
  ~RealmSummary() {}

  void setNode(std::string s) {m_node=s;}
  void addProc(std::string s);

  std::string get_spec() const;

  std::string getNode() const         {return(m_node);}
  std::vector<std::string> getProcs() {return(m_procs);}

  unsigned int size() const {return(m_procs.size());}

  bool valid() const;
  
 private: 
  std::string m_node;

  std::vector<std::string> m_procs;
};

RealmSummary string2RealmSummary(std::string);

#endif 
