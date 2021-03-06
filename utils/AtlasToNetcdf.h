//===--------------------------------------------------------------------------------*- C++ -*-===//
//                          _
//                         | |
//                       __| | __ ___      ___ ___
//                      / _` |/ _` \ \ /\ / / '_  |
//                     | (_| | (_| |\ V  V /| | | |
//                      \__,_|\__,_| \_/\_/ |_| |_| - Compiler Toolchain
//
//
//  This file is distributed under the MIT License (MIT).
//  See LICENSE.txt for details.
//
//===------------------------------------------------------------------------------------------===//

#pragma once

#include <atlas/mesh.h>
#include <string>

// This module offers a function to write a netcdif file
//    - The atlas mesh is either assumed to be "complete" or "minimal"
//    - "minimal" means that only the nodes, and the cell to node nbh table is contained in the
//      atlas mesh
//    - "complete" means that all neighbor tables except onto the element itself (e.g. node->node)
//      are present
//    - otherwise, a mesh is assumed to be "partial" and an error message is printed
//    - the naming convention for all fields and neighbor tables follows the DWD convention, but
//      only a subset of all fields present in DWD generated files (either base grids or grids
//      generated by the web interface) are written (the onces required by AtlasFromNetCDF)

bool AtlasToNetCDF(const atlas::Mesh& mesh, const std::string& filename);